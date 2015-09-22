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
#include <sys/utsname.h> 
#include <string>
#include <cstring>
#include <iostream>
#include <vector>
#include <sys/wait.h>
#include <algorithm>
#include <sys/types.h>
#include <regex>
#include <sstream>
#include <dirent.h>
#include <fcntl.h>
#include <fstream>
using namespace std;

void *cat(vector<string>);

int main(int argc, char const *argv[]) {
	vector<string> data;
	data.push_back("cat");
	data.push_back("test.txt");

	string token = "test3.txt";
	int fd;
    int defout;				 
    if ((defout = dup(1)) < 0){
        fprintf(stderr, "Can't dup(2) - (%s)\n", strerror(errno));
        exit(1);
    }
    if ((fd = open(token.c_str(), O_RDWR | O_TRUNC | O_CREAT, S_IRUSR | S_IWUSR)) < 0){
        fprintf(stderr, "Can't open(2) - (%s)\n", strerror(errno)); exit(1);
    }
    if (dup2(fd, 1) < 0) // redireccionar la salida al archivo
    {
        fprintf(stderr, "Can't dup2(2) - (%s)\n", strerror(errno)); exit(1);
    }
    cat(data);
    close(fd);  //Cerrar archivo
    fflush(stdout);// flush el output al archivo
    // Ahora stdout esta limpio para otro uso
    if (dup2(defout, 1) < 0) // redireccionar el output de nuevo a stdout
    {
        fprintf(stderr, "Can't dup2(2) - (%s)\n", strerror(errno)); exit(1);
    }
    close(defout);  // La copia de stdout no se necesita mas
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