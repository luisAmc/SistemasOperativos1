#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#include <string.h>
#include <sstream>
//I, the guardian of the law, am the only one who can return the corrupted and ruined justice to its true form!
#include <fstream>
#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>
using namespace std;

inline bool isInteger(const string &);
inline vector<string> readStats(string);
vector<string> split(string,char);
const char *DIR_PROC = "/proc";

int main(int argc, char const *argv[])
{						


	vector< vector<string> > ALL_STATS;
	if (argc != 1){
		exit(1);
	}
	string RUN_DIR(argv[0]);
	RUN_DIR+="/cat";
	stringstream SS;
	int fd_p2c[2], fd_c2p[2], bytes_read;
    pid_t childpid;
    char readbuffer[256];
    string receive = "";
	//vector<string> PID;
	DIR *dir;
	struct dirent *ent;
	if ((dir = opendir (DIR_PROC)) != NULL) {
	  /* print all the files and directories within directory */
	  while ((ent = readdir (dir)) != NULL) {
	  	receive="";
	  	if (isInteger(ent->d_name)){
			 if (pipe(fd_p2c) != 0 || pipe(fd_c2p) != 0)  {
			        cerr << "Failed to pipe\n";
			        exit(1);
			}
			childpid = fork();

			if (childpid < 0){
			    cout << "Fork failed" << endl;
			    exit(-1);
			}else if (childpid == 0){
			    if (dup2(fd_p2c[0], 0) != 0 ||
			        close(fd_p2c[0]) != 0 ||
			        close(fd_p2c[1]) != 0){
			            
			            cerr << "Child: failed to set up standard input\n";
			            exit(1);
			    }
			    if (dup2(fd_c2p[1], 1) != 1 ||
			       close(fd_c2p[1]) != 0 ||
			       close(fd_c2p[0]) != 0){
			      	
			      		cerr << "Child: failed to set up standard output\n";
			            exit(1);
			    }
			    string DIR(DIR_PROC);
			    char *arg[] = {(char *)(DIR+"/"+ent->d_name+"/stat").c_str(), (char *)0};
		        execv(RUN_DIR.c_str(), arg);
		        exit(1);
		    }else{
		    	close(fd_p2c[0]);
        		close(fd_c2p[1]);
				while (1){
            		bytes_read = read(fd_c2p[0], readbuffer, sizeof(readbuffer)-1);

            		if (bytes_read <= 0)
                		break;

            		readbuffer[bytes_read] = '\0';
            		receive += readbuffer;
        		}
       			close(fd_c2p[0]);
       			ALL_STATS.push_back(readStats(receive));
       			//cout << "PID" << '\t' << "TTY" << '\t' << "TIME" << '\t' << "CMD" << endl;
       			 //cout << "From child: <<" << receive << ">>" << endl;
		    }
	  	}
	  }
	  closedir (dir);
	} else {
	  /* could not open directory */
	  perror ("");
	}
	/* code */

	cout << "PID" << '\t' << "TTY" << '\t' << "TIME" << '\t' << "CMD" << endl;
	for (int i = 0; i < ALL_STATS.size() ; i++){
		cout << ALL_STATS[i][0] << '\t' << ALL_STATS[i][1] << '\t' << ALL_STATS[i][2] << '\t' << ALL_STATS[i][3] << endl;
	}

	return 0;
}

inline bool isInteger(const string &s)
{
   if(s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false ;

   char * p ;
   strtol(s.c_str(), &p, 10) ;

   return (*p == 0) ;
}

inline vector<string> readStats(string stats){
	vector<string> parseStats = split(stats,' ');
	//*----*ENTRADA
	//PID POSICION 0
	//CMD POSICION 1
	//STATE (RUNNING,SLEEP)) 2
	//PPID POSICION 3
	//TTY_NR? 6
	//UTIME 13 (DIVIDIRLO POR sysconf(_SC_CLK_TCK)))
	vector<string> retVal;
	long TIME;
	retVal.push_back(parseStats[0]);
	retVal.push_back(parseStats[6]);
	retVal.push_back(parseStats[13]);
	retVal.push_back(parseStats[1]);
	//SALIDA
	//0 = PID
	//1 = TTY_NR?
	//2 = UTIME?
	//3 = CMD

	return retVal;
}

vector<string> split(string str, char delimiter) {
  vector<string> internal;
  stringstream ss(str); // Turn the string into a stream.
  string tok;
  
  while(getline(ss, tok, delimiter)) {
    internal.push_back(tok);
  }
  
  return internal;
}