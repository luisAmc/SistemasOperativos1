#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#include <string.h>
#include <sstream>
#include <fstream>
#include <unistd.h>
using namespace std;

const string COMANDOS[] = {"ln","cat","ps"};
const int COMANDOS_SIZE = 3;

int checkCommand(string);
void *cat(vector<string>);
void *ln(vector<string>);
vector<string> split(string str, char delimiter);


int main(int argc, char const *argv[])
{

	while(1){
		cout << "MyBASH> ";
		char COM[256];
		cin.getline(COM , 256);
		vector<string> ComandoVector = split(COM,' ');
		if (ComandoVector.size() == 0){
			cout << "ENTRADA VACIA" << endl;
			continue;
		}
		int indexComando;
		if ((indexComando = checkCommand(ComandoVector[0])) != -1){
			if (COMANDOS[indexComando] == "cat"){
				cat(ComandoVector);
			}else if (COMANDOS[indexComando] == "ln"){
				ln(ComandoVector);
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

void *cat(vector<string> ParseComando){
	if (ParseComando.size() == 2){
		char *arg[] = {(char *)ParseComando[1].c_str(), (char *)0};
		if (!fork()){
			execv("./cat", arg);
		}
	}else{
		if (!fork()){
			execv("./cat", NULL);
		}
	}
}

void *ln(vector<string> ParseComando){
	if (ParseComando.size() == 2){
		char *arg[] = {(char *)ParseComando[1].c_str(), (char *)0};
		if (!fork()){
			execv("./ln", arg);
		}
	}else if (ParseComando.size() == 3){
		char *arg[] = {(char *)ParseComando[1].c_str(),(char *)ParseComando[2].c_str(), (char *)0};
		if (!fork()){
			execv("./ln", arg);
		}
	}else if (ParseComando.size() == 4){
		char *arg[] = {(char *)ParseComando[1].c_str(),(char *)ParseComando[2].c_str(),(char *)ParseComando[3].c_str(), (char *)0};
		if (!fork()){
			execv("./ln", arg);
		}
	}else{
		if (!fork()){
			execv("./ln", NULL);
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