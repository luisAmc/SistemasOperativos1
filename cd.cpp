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
int main(int argc, char const *argv[]){
	cout<<"Entre"<<endl;
	
	if(argc==1){
		
		
		if(chdir(argv[0])==-1){

			printf ("chdir failed - %s\n", strerror (errno)); 
		}else {  

        printf ("chdir done !!!\n");  
        printf ("directory content of '%s'\n\n", argv[0]);  
        system ("ls -l");
		}
	}


	return 0;
}