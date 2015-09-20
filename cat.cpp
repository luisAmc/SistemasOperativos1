#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#include <string.h>
#include <sstream>
#include <fstream>
#include <unistd.h>

using namespace std;

int main(int argc, char const *argv[])
{
	//cout << endl;
	if (argc == 1){
		ifstream catFile(argv[0]);
		string LINE;
		if (catFile.is_open()){
			while (getline(catFile,LINE)){
				cout << LINE << endl;
			}
			catFile.close();
		}else{
			cout << "ERROR AL ABRIR ARCHIVO " << argv[0] << endl;
		}
	}else{
		char LINE[256];
		cout << "ENTER" << endl;
		cin.getline(LINE,256);
		do{
			cout << LINE << endl;
		}while ((cin >> LINE));
	}
	//cout << endl;
	return 0;
}