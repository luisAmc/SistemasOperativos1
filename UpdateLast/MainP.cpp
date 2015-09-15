#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#include <string.h>
#include <sstream>
#include <fstream>
#include <unistd.h>
#include <errno.h>  
#include <stdlib.h> 
using namespace std;
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
int main(int argc, char const *argv[]){
	while(true){
		cout<<"MyBash>";
		char COM[256];
		cin.getline(COM,256);
		vector<string> ComandoVector=split(COM,' ');
		if(ComandoVector.size()==0){
			cout<<"Entrada Vacia"<<endl;
			continue;
		}
		int indexComando;
		if ((indexComando = checkCommand(ComandoVector[0])) != -1){
			if (COMANDOS[indexComando] == "cd"){
				cd(ComandoVector);
			}else if (COMANDOS[indexComando] == "chmod"){
				chmod(ComandoVector);
			}else if(COMANDOS[indexComando]=="uname"){
				uname(ComandoVector);
			}else if (COMANDOS[indexComando] == "kill"){
				cout<<"No se que pedales por aqui"<<endl;
			}else if (COMANDOS[indexComando] == "cat"){
				cat(ComandoVector);
			}else if (COMANDOS[indexComando] == "ln"){
				ln(ComandoVector);
			}else if(COMANDOS[indexComando] == "mkdir"){
				cmd_mkDir(ComandoVector);
			}else if(COMANDOS[indexComando] == "rmdir"){
				cmd_rmDir(ComandoVector);
			}else if(COMANDOS[indexComando] == "rm"){
				cmd_rmFile(ComandoVector);
			}else if(COMANDOS[indexComando] == "ls"){
				system ("ls -l");
			}
		}else{
			cout << "COMANDO NO ENCONTRADO " << endl;
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
				execv("/home/carlos/SistemasOperativosP/chmod",arg);
			}
		}
	}
	void *uname(vector<string> ParseComando){
		if(ParseComando.size()==2){
			char *arg[] = {(char *)ParseComando[1].c_str(), (char *)0};
			if (!fork()){
				execv("/home/carlos/SistemasOperativosP/uname", arg);
			}
		}
		if(ParseComando.size()==3){
			char *arg[] = {(char *)ParseComando[1].c_str(),(char *)ParseComando[2].c_str(), (char *)0};
			if (!fork()){
				execv("/home/carlos/SistemasOperativosP/uname", arg);
			}
		}
		if(ParseComando.size()==4){
			char *arg[] = {(char *)ParseComando[1].c_str(),(char *)ParseComando[2].c_str(),(char *)ParseComando[3].c_str(), (char *)0};
			if (!fork()){
				execv("/home/carlos/SistemasOperativosP/uname", arg);
			}
		}
		if(ParseComando.size()==5){
			char *arg[] = {(char *)ParseComando[1].c_str(),(char *)ParseComando[2].c_str(),(char *)ParseComando[3].c_str(), (char *)ParseComando[4].c_str(),(char *)0};
			if (!fork()){
				execv("/home/carlos/SistemasOperativosP/uname", arg);
			}
		}


	}
	void *cat(vector<string> ParseComando){
		if (ParseComando.size() == 2){
			char *arg[] = {(char *)ParseComando[1].c_str(), (char *)0};
			if (!fork()){
				execv("/home/carlos/SistemasOperativos1/UpdateLast/cat", arg);
			}
		}else{
			if (!fork()){
				execv("/home/carlos/SistemasOperativos1/UpdateLast/cat", NULL);
			}
		}
	}

	void *ln(vector<string> ParseComando){
		if (ParseComando.size() == 2){
			char *arg[] = {(char *)ParseComando[1].c_str(), (char *)0};
			if (!fork()){
				execv("/home/carlos/SistemasOperativos1/UpdateLast/ln", arg);
			}
		}else if (ParseComando.size() == 3){
			char *arg[] = {(char *)ParseComando[1].c_str(),(char *)ParseComando[2].c_str(), (char *)0};
			if (!fork()){
				execv("/home/carlos/SistemasOperativos1/UpdateLast/ln", arg);
			}
		}else if (ParseComando.size() == 4){
			char *arg[] = {(char *)ParseComando[1].c_str(),(char *)ParseComando[2].c_str(),(char *)ParseComando[3].c_str(), (char *)0};
			if (!fork()){
				execv("/home/carlos/SistemasOperativos1/UpdateLast/ln", arg);
			}
		}else{
			if (!fork()){
				execv("/home/carlos/SistemasOperativos1/UpdateLast/ln", NULL);
			}
		}
	}
	void *cmd_mkDir(vector<string> ParseComando) {
	//char *arg[] = {(char *)("./" + path).c_str(), (char *)0};

		if(ParseComando.size()==2){

			char *arg[] = {(char *)ParseComando[1].c_str(), (char *)0};
			if (!fork()) {
				execv("/home/carlos/SistemasOperativos1/UpdateLast/cmd_mkDir", arg);

			}
		}

	}
	void *cmd_rmDir(vector<string> ParseComando) {
		if(ParseComando.size()==2){
			char *arg[] = {(char *)ParseComando[1].c_str(), (char *)0};
			if (!fork()) {
				execv("/home/carlos/SistemasOperativos1/UpdateLast/cmd_rmDir", arg);

			}
		}else if(ParseComando.size()==3){
				string opcion = ParseComando[1];
				if(opcion=="-R"){
				char *arg[] = {(char *)ParseComando[2].c_str(), (char *)0};
				if (!fork()) {
					execv("/home/carlos/SistemasOperativos1/UpdateLast/cmd_rmDirR", arg);

				}
			}
		}

	}
	void *cmd_rmFile(vector<string> ParseComando) {
	if(ParseComando.size()==2){
	char *arg[] = {(char *)ParseComando[1].c_str(), (char *)0};
	if (!fork()) {
		execv("/home/carlos/SistemasOperativos1/UpdateLast/cmd_rmFile", arg);
		
	}	
	}
	}