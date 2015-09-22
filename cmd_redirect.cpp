#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#include <string.h>
#include <sstream>
#include <fstream>
#include <unistd.h>
#include <errno.h>  
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h> 
#include <unistd.h>
#include <sys/stat.h> 
#include <sys/wait.h> 
#include <sys/utsname.h> 
#include <string>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
#include <sys/types.h>
#include <sstream>
#include <dirent.h>
#include <fcntl.h>
#include <fstream>
using namespace std;


char RUN_DIR[FILENAME_MAX];
vector<string> split(string, char);
void *cat(vector<string>);
void *ps(vector<string>, string);

int main(int argc, char const *argv[]) {
	vector<string> commands;
	commands.push_back("cat");
	commands.push_back("ls");
	commands.push_back("ps");

	vector<string> first_command = split(argv[0], ' ');
	if (first_command[0].find(" ") != string::npos) {
		first_command[0] = first_command[0].substr(0, first_command[0].length() - 1);
	}

	int fd;
	int defout;
	argv[1]++;
	string outfile = argv[1];//test.txt
	defout = dup(1);
	fd = open(outfile.c_str(), O_RDWR | O_TRUNC | O_CREAT, S_IRUSR | S_IWUSR);
	dup2(fd, 1);

	if (first_command[0].compare(commands[0]) == 0) {
		cat(first_command);
		int status = 0;
		while((wait(&status)) != -1);

	} else if (first_command[0].compare(commands[1]) == 0){
		system ("ls -l");
		//ls(first_command);
	} else if (first_command[0].compare(commands[2]) == 0){
		ps(first_command, RUN_DIR);
		int status = 0;
		while((wait(&status)) != -1);
	}
	
	//cat(data);
	
	close(fd);

	fflush(stdout);
	dup2(defout, 1);
	close(defout);
	return 0;
}

void *cat(vector<string> ParseComando){
	string com = "cat";
	if (ParseComando.size() == 2){
		char *arg[] = {(char *)ParseComando[1].c_str(), (char *)0};
		if (!fork()){
			execv((com).c_str(),arg);
		}
	}else{
		if (!fork()){
			execv((com).c_str(),NULL);
		}
	}
}

void *ps(vector<string> ParseComando, string RUN_DIR){
	string com = "ps";
	if(ParseComando.size()==1){
		char *arg[] = {(char *)RUN_DIR.c_str(), (char *)0};
		if (!fork()) {

			execv((com).c_str(),arg);
		}
	}	
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