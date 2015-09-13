#include <iostream>
#include <string>
#include <unistd.h>
#include <pthread.h>
using namespace std;

int menu();
void *cmdMkDirThread(void *);
void *cmdRmDirThread(void *);
int cmd_mkDir(string);
int cmd_rmDir(string);
int cmd_rmDirR(string);

int main(int argc, char const *argv[]) {
	bool keep_going = true;
	int option = 0;
	while ((option = menu()) > 0) {
		switch (option) {
			case 0:
			{
				keep_going = false;
				break;
			}
			case 1:
			{
				string folder_path = "";
				cout << "\nIngrese la direccion del nuevo directorio: " << endl;
				getline(cin, folder_path);
				getline(cin, folder_path);
				pthread_t *mkDir = new pthread_t;
				pthread_create(mkDir, NULL, cmdMkDirThread, (void *)(&folder_path));
				pthread_join(*mkDir, NULL);
				break;
			}
			case 2:
			{
				string folder_path = "";
				cout << "\nIngrese la direccion del directorio a borrar (El directorio tiene que estar vacio): " << endl;
				getline(cin, folder_path);
				getline(cin, folder_path);
				pthread_t *rmDir = new pthread_t;
				pthread_create(rmDir, NULL, cmdRmDirThread, (void *)(&folder_path));
				pthread_join(*rmDir, NULL);
				break;
			}
		}
	}
	return 0;
}

int menu() {
	int opcion = 0;
	cout << "\n---- Menu ----\n"
		<< "0. SALIR\n"
		<< "1. Crear directorio\n"
		<< "2. Remover directorio\n"
		<< "3. Remover directorio (Recursivo)\n"
		<< "4. Remover un archivo\n"
		<< "Ingrese la opcion:" << endl; 
	cin >> opcion;
	return opcion;
}

void *cmdMkDirThread(void *p) {
	string *folder_to_create = (string *)p;
	if (!cmd_mkDir(*folder_to_create))
		pthread_exit(NULL);
}

int cmd_mkDir(string path) {
	//char *arg[] = {(char *)("./" + path).c_str(), (char *)0};
	char *arg[] = {(char *)path.c_str(), (char *)0};
	if (fork() == 0) {
		execv("./cmd_mkDir", arg);
		return 0;
	}
	return 1;
}

void *cmdRmDirThread(void *p) {
	string *folder_to_delete = (string *)p;
	if (!cmd_rmDir(*folder_to_delete))
		pthread_exit(NULL);
}

int cmd_rmDir(string path) {
	char *arg[] = {(char *)path.c_str(), (char *)0};
	if (fork() == 0) {
		execv("./cmd_rmDir", arg);
		return 0;
	}
	return 1;
}