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
#include <sys/stat.h>

using namespace std;
int main(int argc,char const *argv[]){
	if(argc==2){
		
    	
    	int i;
    	i = strtol(argv[0], 0, 8);
    	if (chmod (argv[1],i) < 0)
        	printf("error in chmod");
		}else{
			system ("ls -l");
		}
	return 0;
}