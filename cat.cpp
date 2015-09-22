#include <iostream>
#include <string>
#include <fstream>

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
		string LINE;
		//cout << "ENTER" << endl;
		while (getline(cin,LINE)){
			cout << LINE << endl;
		}
	}
	//cout << endl;
	return 0;
}