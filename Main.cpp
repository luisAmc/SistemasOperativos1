#include <iostream>
#include <string>
#include <unistd.h>
#include <pthread.h>
using namespace std;

int menu();
void *cmdMkDirThread(void *);
void *cmdRmDirThread(void *);
void *cmdRmFileThread(void *);
void *cmdRmDirRThread(void *);
int cmd_mkDir(string);
int cmd_rmDir(string);
int cmd_rmDirR(string);
int cmd_rmFile(string);

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
				//mkDir
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
				//rmDir
				string folder_path = "";
				cout << "\nIngrese la direccion del directorio a eliminiar (El directorio tiene que estar vacio): " << endl;
				getline(cin, folder_path);
				getline(cin, folder_path);
				pthread_t *rmDir = new pthread_t;
				pthread_create(rmDir, NULL, cmdRmDirThread, (void *)(&folder_path));
				pthread_join(*rmDir, NULL);
				break;
			}
			case 3:
			{
				//rmDir -R
				string folder_path = "";
				cout << "\nIngrese la direccion del directorio a eliminiar: " << endl;
				getline(cin, folder_path);
				getline(cin, folder_path);
				pthread_t *rmDirR = new pthread_t;
				pthread_create(rmDirR, NULL, cmdRmDirRThread, (void *)(&folder_path));
				pthread_join(*rmDirR, NULL);
				break;
			}
			case 4:
			{
				//rm
				string folder_path = "";
				cout << "\nIngrese la direccion del archivo a eliminiar: " << endl;
				getline(cin, folder_path);
				getline(cin, folder_path);
				pthread_t *rmFile = new pthread_t;
				pthread_create(rmFile, NULL, cmdRmFileThread, (void *)(&folder_path));
				pthread_join(*rmFile, NULL);
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
	if (!fork()) {
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
	if (!fork()) {
		execv("./cmd_rmDir", arg);
		return 0;
	}
	return 1;
}

void *cmdRmFileThread(void *p) {
	string *file_to_delete = (string *)p;
	if (!cmd_rmFile(*file_to_delete))
		pthread_exit(NULL);
}

int cmd_rmFile(string path) {
	char *arg[] = {(char *)path.c_str(), (char *)0};
	if (!fork()) {
		execv("./cmd_rmFile", arg);
		return 0;
	}	
	return 1;
}

void *cmdRmDirRThread(void *p) {
	string *folder_to_delete_recursively = (string *)p;
	if (!cmd_rmDirR(*folder_to_delete_recursively))
		pthread_exit(NULL);
}

int cmd_rmDirR(string path) {
	char *arg[] = {(char *)path.c_str(), (char *)0};
	if (!fork()) {
		execv("./cmd_rmDirR", arg);
		return 0;
	}
	return 1;
}