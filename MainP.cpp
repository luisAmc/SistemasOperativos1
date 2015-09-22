#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#include <string.h>
#include <sstream>
#include <fstream>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>  
#include <dirent.h>
#include <stdlib.h> 
using namespace std;
char RUN_DIR[FILENAME_MAX];
const string COMANDOS[] = {"cd","chmod","uname","kill","ln","cat","ps","mkdir","ls","rmdir","rm"};
const int COMANDOS_SIZE = 11;


int checkCommand(string);
vector<string> split(string str, char delimiter);
void *cd(vector<string>);
void *chmod(vector<string>);
void *uname(vector<string>);
void *cat(vector<string>);
void *ln(vector<string>);
void *cmd_mkDir(vector<string>);
void *cmd_rmDir(vector<string>);
void *cmd_rmFile(vector<string>);
void *ps(vector<string>,string);
void *kill(vector<string>);
void *redireccionamiento(vector<string>);
void *cmd_ls(vector<string>);

int main(int argc, char const *argv[]){
	getcwd(RUN_DIR,sizeof(RUN_DIR));
	cout << RUN_DIR << endl;
	while(true){
		cout<<"MyBash>";
		char COM[256];
		cin.getline(COM,256);
		vector<string> ComandoVector=split(COM,' ');
		if(ComandoVector.size()==0){
			cout<<"Entrada Vacia"<<endl;
			continue;
		}

		string comando = COM;
		if (comando.find(">") != string::npos) {
			vector<string> data = split(comando, '>');
			redireccionamiento(data);
			int status = 0;
			while((wait(&status)) != -1);
		} else {

			int indexComando;
			if ((indexComando = checkCommand(ComandoVector[0])) != -1){
				if (COMANDOS[indexComando] == "cd"){
					cd(ComandoVector);
				//cout << endl;
				}else if (COMANDOS[indexComando] == "chmod"){
					chmod(ComandoVector);
				//cout << endl;
				}else if(COMANDOS[indexComando]=="uname"){
					uname(ComandoVector);
				//cout << endl;
				}else if (COMANDOS[indexComando] == "kill"){
					kill(ComandoVector);
				//cout << endl;
				}else if (COMANDOS[indexComando] == "cat"){
					cat(ComandoVector);
					int status = 0;
					while((wait(&status)) != -1);
				//cout << endl;
				}else if (COMANDOS[indexComando] == "ln"){
					ln(ComandoVector);
				//cout << endl;
				}else if(COMANDOS[indexComando] == "mkdir"){
					cmd_mkDir(ComandoVector);
				//cout << endl;
				}else if(COMANDOS[indexComando] == "rmdir"){
					cmd_rmDir(ComandoVector);
				//cout << endl;
				}else if(COMANDOS[indexComando] == "rm"){
					cmd_rmFile(ComandoVector);
				//cout << endl;
				}else if(COMANDOS[indexComando] == "ls"){
					cmd_ls(ComandoVector);
					int status = 0;
					while((wait(&status)) != -1);
					//system ("ls -l");
				}else if(COMANDOS[indexComando] == "ps"){
					ps(ComandoVector,RUN_DIR);
					int status = 0;
					while((wait(&status)) != -1);
				//cout << endl;
				}
			}else{
				cout << "COMANDO NO ENCONTRADO " << endl;
			}
		}
	}
	return 0;
}
int checkCommand(string Comando){

	for (int i = 0; i < COMANDOS_SIZE; ++i)
	{
		if (Comando == COMANDOS[i])
			return i;
	}
	return -1;
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

void *cmd_ls(vector<string> ParseComando) {
	if (ParseComando.size() == 1)
		ParseComando.push_back("./");
	char *arg[] = {(char *)ParseComando[1].c_str(), (char *)0};
	if (!fork()) {
		string EXEC_COMMAND(RUN_DIR);
		EXEC_COMMAND += "/cmd_ls";
		execv(EXEC_COMMAND.c_str(),arg);

	}
}

void *redireccionamiento(vector<string> ParseComando) {
	char *arg[] = {(char *)ParseComando[0].c_str(), (char *)ParseComando[1].c_str(), (char *)0};
	if (!fork()) {
		string EXEC_COMMAND(RUN_DIR);
		EXEC_COMMAND += "/cmd_redirect";
		execv(EXEC_COMMAND.c_str(), arg);
	}
}

void *cd(vector<string> ParseComando){
	if(ParseComando.size()==2){
		if(chdir((char *)ParseComando[1].c_str())==-1){

			printf ("cd failed - %s\n", strerror (errno)); 
		}else {  

			printf ("chdir done !!!\n");  
			printf ("directory content of '%s'\n\n", ((char *)ParseComando[1].c_str()));  
			system ("ls -l");
		}
	/*char *arg[]={(char *)ParseComando[1].c_str(),(char *)0};
	if(!fork()){
		execv("./cd",arg);
	}*/
	}else{
	//if(!fork()){
	//		execv("./cd",NULL);
	//}
	}
}
void *chmod(vector<string> ParseComando){
	if(ParseComando.size()==3){
		char *arg[] = {(char *)ParseComando[1].c_str(),(char *)ParseComando[2].c_str(), (char *)0}; 
		if(!fork()){
			string EXEC_COMMAND(RUN_DIR);
			EXEC_COMMAND += "/chmod";
			execv(EXEC_COMMAND.c_str(),arg);
		}
	}
}
void *uname(vector<string> ParseComando){
	if(ParseComando.size()==2){
		char *arg[] = {(char *)ParseComando[1].c_str(), (char *)0};
		if (!fork()){
			string EXEC_COMMAND(RUN_DIR);
			EXEC_COMMAND += "/uname";
			execv(EXEC_COMMAND.c_str(),arg);
		}
	}
	if(ParseComando.size()==3){
		char *arg[] = {(char *)ParseComando[1].c_str(),(char *)ParseComando[2].c_str(), (char *)0};
		if (!fork()){
			string EXEC_COMMAND(RUN_DIR);
			EXEC_COMMAND += "/uname";
			execv(EXEC_COMMAND.c_str(),arg);
		}
	}
	if(ParseComando.size()==4){
		char *arg[] = {(char *)ParseComando[1].c_str(),(char *)ParseComando[2].c_str(),(char *)ParseComando[3].c_str(), (char *)0};
		if (!fork()){
			string EXEC_COMMAND(RUN_DIR);
			EXEC_COMMAND += "/uname";
			execv(EXEC_COMMAND.c_str(),arg);
		}
	}
	if(ParseComando.size()==5){
		char *arg[] = {(char *)ParseComando[1].c_str(),(char *)ParseComando[2].c_str(),(char *)ParseComando[3].c_str(), (char *)ParseComando[4].c_str(),(char *)0};
		if (!fork()){
			string EXEC_COMMAND(RUN_DIR);
			EXEC_COMMAND += "/uname";
			execv(EXEC_COMMAND.c_str(),arg);
		}
	}


}
void *cat(vector<string> ParseComando){
	if (ParseComando.size() == 2){
		char *arg[] = {(char *)ParseComando[1].c_str(), (char *)0};
		if (!fork()){
			string EXEC_COMMAND(RUN_DIR);
			EXEC_COMMAND += "/cat";
			execv(EXEC_COMMAND.c_str(),arg);
		}
	}else{
		if (!fork()){
			string EXEC_COMMAND(RUN_DIR);
			EXEC_COMMAND += "/cat";
			execv(EXEC_COMMAND.c_str(),NULL);
		}
	}
}

void *ln(vector<string> ParseComando){
	if (ParseComando.size() == 2){
		char *arg[] = {(char *)ParseComando[1].c_str(), (char *)0};
		if (!fork()){
			string EXEC_COMMAND(RUN_DIR);
			EXEC_COMMAND += "/ln";
			execv(EXEC_COMMAND.c_str(),arg);
		}
	}else if (ParseComando.size() == 3){
		char *arg[] = {(char *)ParseComando[1].c_str(),(char *)ParseComando[2].c_str(), (char *)0};
		if (!fork()){
			string EXEC_COMMAND(RUN_DIR);
			EXEC_COMMAND += "/ln";
			execv(EXEC_COMMAND.c_str(),arg);
		}
	}else if (ParseComando.size() == 4){
		char *arg[] = {(char *)ParseComando[1].c_str(),(char *)ParseComando[2].c_str(),(char *)ParseComando[3].c_str(), (char *)0};
		if (!fork()){
			string EXEC_COMMAND(RUN_DIR);
			EXEC_COMMAND += "/ln";
			execv(EXEC_COMMAND.c_str(),arg);
		}
	}else{
		if (!fork()){
			string EXEC_COMMAND(RUN_DIR);
			EXEC_COMMAND += "/ln";
			execv(EXEC_COMMAND.c_str(),NULL);
		}
	}
}
void *cmd_mkDir(vector<string> ParseComando) {
//char *arg[] = {(char *)("./" + path).c_str(), (char *)0};

	if(ParseComando.size()==2){

		char *arg[] = {(char *)ParseComando[1].c_str(), (char *)0};
		if (!fork()) {
			string EXEC_COMMAND(RUN_DIR);
			EXEC_COMMAND += "/cmd_mkDir";
			execv(EXEC_COMMAND.c_str(),arg);

		}
	}

}
void *cmd_rmDir(vector<string> ParseComando) {
	if(ParseComando.size()==2){
		char *arg[] = {(char *)ParseComando[1].c_str(), (char *)0};
		if (!fork()) {
			string EXEC_COMMAND(RUN_DIR);
			EXEC_COMMAND += "/cmd_rmDir";
			execv(EXEC_COMMAND.c_str(),arg);

		}
	}else if(ParseComando.size()==3){
		string opcion = ParseComando[1];
		if(opcion=="-R"){
			char *arg[] = {(char *)ParseComando[2].c_str(), (char *)0};
			if (!fork()) {
				string EXEC_COMMAND(RUN_DIR);
				EXEC_COMMAND += "/cmd_rmDirR";
				execv(EXEC_COMMAND.c_str(),arg);

			}
		}
	}

}
void *cmd_rmFile(vector<string> ParseComando) {
	if(ParseComando.size()==2){
		char *arg[] = {(char *)ParseComando[1].c_str(), (char *)0};
		if (!fork()) {
			string EXEC_COMMAND(RUN_DIR);
			EXEC_COMMAND += "/cmd_rmFile";
			execv(EXEC_COMMAND.c_str(),arg);
			
		}	
	}
}

void *ps(vector<string> ParseComando, string RUN_DIR){
	if(ParseComando.size()==1){
		char *arg[] = {(char *)RUN_DIR.c_str(), (char *)0};
		if (!fork()) {
			string EXEC_COMMAND(RUN_DIR);
			EXEC_COMMAND += "/ps";
			execv(EXEC_COMMAND.c_str(),arg);
		}
	}	
}
void *kill(vector<string> ParseComando){
	if(ParseComando.size()==3){
		char *arg[] = {(char *)ParseComando[2].c_str(), (char *)0};
		if (!fork()) {
			string EXEC_COMMAND(RUN_DIR);
			EXEC_COMMAND += "/kill";
			execv(EXEC_COMMAND.c_str(),arg);
		}
	}
}