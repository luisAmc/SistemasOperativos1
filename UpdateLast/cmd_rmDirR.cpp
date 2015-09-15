#include <unistd.h>
#include <iostream>
#include <stack>
#include <dirent.h>
using namespace std;

int main(int argc, char const *argv[]) {
	DIR *dir, *dir2;
	struct dirent *entry;
	int folder_count = 1;

	stack<string> folder_stack;
	string actual_folder = "./" + (string)argv[0];
	folder_stack.push(actual_folder);
	

	//cout << "El folder actual es " << actual_folder << endl;

	while (folder_count > 0) {
		folder_count = 0;
		if (dir = opendir((char *)folder_stack.top().c_str())) {
			actual_folder = folder_stack.top();
			while (entry = readdir(dir)) 
				if (entry->d_type == DT_DIR) {
					folder_count++;
					if ((((string)entry->d_name).compare(".") != 0) && (((string)entry->d_name).compare("..") != 0))
						folder_stack.push(actual_folder + "/" + (string)entry->d_name);
				} else
					unlink((char *)(actual_folder + "/" + entry->d_name).c_str());
		}
	}
	closedir(dir);

	while (!folder_stack.empty()) {
		rmdir((char *)(folder_stack.top().c_str()));
		folder_stack.pop();
	}
	
	return 0;
}