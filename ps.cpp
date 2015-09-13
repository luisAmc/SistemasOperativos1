#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#include <string.h>
#include <sstream>
//I, the guardian of the law, am the only one who can return the corrupted and ruined justice to its true form!
#include <fstream>
#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>
using namespace std;

inline bool isInteger(const string &);
const string DIR_PROC = "/proc";

int main(int argc, char const *argv[])
{						

	stringstream SS;
	vector<string> PID;
	DIR *dir;
	struct dirent *ent;
	if ((dir = opendir (DIR_PROC)) != NULL) {
	  /* print all the files and directories within directory */
	  while ((ent = readdir (dir)) != NULL) {
	  	if (isInteger(ent->d_name)){
	  		printf ("%s\n", ent->d_name);
	  		PID.push_back(ent->d_name);
	  	}
	  }
	  closedir (dir);
	} else {
	  /* could not open directory */
	  perror ("");
	}
	/* code */
	return 0;
}

inline bool isInteger(const string &s)
{
   if(s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false ;

   char * p ;
   strtol(s.c_str(), &p, 10) ;

   return (*p == 0) ;
}