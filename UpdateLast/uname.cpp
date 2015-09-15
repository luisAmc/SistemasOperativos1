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
#include <sys/utsname.h>
using namespace std;

int main(int argc, char const *argv[])
{
	cout<<"Hola Mundo"<<endl;
	if(argc<5){
		int z;
		struct utsname u_name;
		z = uname(&u_name);

		if ( z == -1 ) {
			fprintf(stderr, "%s: uname(2)\n",
				strerror(errno));
			exit(1);
		}
		if(argc==1){
			string opcion(argv[0]);
			if(opcion=="-a"){

				printf(" System Nanem   = '%s';\n", u_name.sysname);
				printf(" Kernel Name  = '%s';\n", u_name.nodename);
				printf(" Release   = '%s';\n", u_name.release);
				printf(" Version   = '%s';\n", u_name.version);
				printf(" Machine   = '%s';\n", u_name.machine);
			}
			if(opcion=="-s"){
				printf(" System Nanem   = '%s';\n", u_name.sysname);
			}
			if(opcion=="-r"){
				printf(" Kernel Name  = '%s';\n", u_name.nodename);
			}
			if(opcion=="-m"){
				printf(" Machine   = '%s';\n", u_name.machine);
			}
		}
		if(argc==2){
			for (int i = 0; i < argc; ++i)
			{
				
				string opcion(argv[i]);
				if(opcion=="-a"){

					printf(" System Nanem   = '%s';\n", u_name.sysname);
					printf(" Kernel Name  = '%s';\n", u_name.nodename);
					printf(" Release   = '%s';\n", u_name.release);
					printf(" Version   = '%s';\n", u_name.version);
					printf(" Machine   = '%s';\n", u_name.machine);
				}
				if(opcion=="-s"){
					printf(" System Nanem   = '%s';\n", u_name.sysname);
				}
				if(opcion=="-r"){
					printf(" Kernel Name  = '%s';\n", u_name.nodename);
				}
				if(opcion=="-m"){
					printf(" Machine   = '%s';\n", u_name.machine);
				}
			}
		}
		if(argc==3){
			for (int i = 0; i < argc; ++i)
			{
				
				string opcion(argv[i]);
				if(opcion=="-a"){

					printf(" System Nanem   = '%s';\n", u_name.sysname);
					printf(" Kernel Name  = '%s';\n", u_name.nodename);
					printf(" Release   = '%s';\n", u_name.release);
					printf(" Version   = '%s';\n", u_name.version);
					printf(" Machine   = '%s';\n", u_name.machine);
				}
				if(opcion=="-s"){
					printf(" System Nanem   = '%s';\n", u_name.sysname);
				}
				if(opcion=="-r"){
					printf(" Kernel Name  = '%s';\n", u_name.nodename);
				}
				if(opcion=="-m"){
					printf(" Machine   = '%s';\n", u_name.machine);
				}
			}	
		}
		if(argc==4){
			for (int i = 0; i < argc; ++i)
			{
				
				string opcion(argv[i]);
				if(opcion=="-a"){

					printf(" System Nanem   = '%s';\n", u_name.sysname);
					printf(" Kernel Name  = '%s';\n", u_name.nodename);
					printf(" Release   = '%s';\n", u_name.release);
					printf(" Version   = '%s';\n", u_name.version);
					printf(" Machine   = '%s';\n", u_name.machine);
				}
				if(opcion=="-s"){
					printf(" System Nanem   = '%s';\n", u_name.sysname);
				}
				if(opcion=="-r"){
					printf(" Kernel Name  = '%s';\n", u_name.nodename);
				}
				if(opcion=="-m"){
					printf(" Machine   = '%s';\n", u_name.machine);
				}
			}
		}
		
		
	}else{
		cout<<"Comando Incorrecto";
	}
	return 0;
}