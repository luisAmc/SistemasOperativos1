#include <unistd.h>
#include <iostream>
#include <stack>
#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
using namespace std;

string getPersissions(int);

int main(int argc, char const *argv[]) {
	DIR *dir, *dir2;
	struct dirent *entry;
	struct stat results;
	int file_mode;

	string actual_folder = "./" + (string)argv[0];

	//cout << "El folder actual es " << actual_folder << endl;
	if (dir = opendir((char *)actual_folder.c_str())) 
		while (entry = readdir(dir)) {
			stat(entry->d_name, &results);
			file_mode = results.st_mode;
			cout << getPersissions(file_mode) << "\t" << entry->d_name << endl;
			// cout << entry->d_name << "|" << entry->d_reclen << "|" << entry->d_type << endl;
			// cout << "Owner mode: " << results.st_mode << endl;
		}
	closedir(dir);	
	return 0;
}

string getPersissions(int file_mode) {
	string retVal = "";
	retVal += "-";
    if ((file_mode & S_IRUSR) && (file_mode & S_IREAD))
      retVal += "r";
    else
      retVal += "-";
    if ((file_mode & S_IWUSR) && (file_mode & S_IWRITE)) 
      retVal += "w";
    else
      retVal += "-";
    if ((file_mode & S_IXUSR) && (file_mode & S_IEXEC))
      retVal += "x";
    else
      retVal += "-";
    if ((file_mode & S_IRGRP) && (file_mode & S_IREAD))
      retVal += "r";
    else
      retVal += "-";
    if ((file_mode & S_IWGRP) && (file_mode & S_IWRITE))
      retVal += "w";
    else
      retVal += "-";
    if ((file_mode & S_IXGRP) && (file_mode & S_IEXEC))
      retVal += "x";
    else
      retVal += "-";
    if ((file_mode & S_IROTH) && (file_mode & S_IREAD))
      retVal += "r";
    else
      retVal += "-";
    if ((file_mode & S_IWOTH) && (file_mode & S_IWRITE))
      retVal += "w";
    else
      retVal += "-";
    if ((file_mode & S_IXOTH) && (file_mode & S_IEXEC))
      retVal += "x   ";
  return retVal;
}