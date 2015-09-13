#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#include <string.h>
#include <sstream>
#include <fstream>
#include <unistd.h>

using namespace std;

vector<string> split(string,char);

int main(int argc, char const *argv[])
{

	if (argc <= 1 || argc > 3){
		cout << "LN necesita la opcion -s y el path al archivo y/o el archivo destino" << endl;
	}else if (argc == 2){
		string opcion(argv[0]);
		if (opcion == "-s"){
			vector<string> listPath = split(argv[1],'/');
			if (symlink(argv[1],listPath[listPath.size() - 1].c_str()) == -1){
				cout << "No se pudo crear el link" << endl;
			}
		}else{
			cout << "Opcion no reconocida" << endl;
		}
	}else if (argc == 3){
		string opcion(argv[0]);
		if (opcion == "-s"){
			if (symlink(argv[1],argv[2]) == -1){
				cout << "No se pudo crear el link" << endl;
			}
		}else{
			cout << "Opcion no reconocida" << endl;
		}
	}
	return 0;
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