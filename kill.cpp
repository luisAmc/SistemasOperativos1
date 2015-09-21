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
#include <signal.h> 
using namespace std;
int main(int argc, char const *argv[]){
string hi=argv[0];
int probando=atoi(hi.c_str());
pid_t id=(pid_t)probando;
kill(id,SIGKILL);
return 0;

}