#include <unistd.h>
#include <iostream>
#include <stack>
#include <dirent.h>
using namespace std;

int main(int argc, char const *argv[]) {
	DIR *dir;
	struct dirent *entry;

	stack<string> folder_stack;
	string actual_folder = "./" + (string)argv[0];
	folder_stack.push(actual_folder);

	//cout << "El folder actual es " << actual_folder << endl;

	if (dir = opendir((char *)folder_stack.top().c_str())) 
		while (entry = readdir(dir)) 
			if (entry->d_type == DT_DIR) 
				if ((((string)entry->d_name).compare(".") != 0) && (((string)entry->d_name).compare("..") != 0)) {
					actual_folder += "/" + (string)entry->d_name; 
					folder_stack.push(actual_folder);
				}


	while (!folder_stack.empty()) {
		cout << "Thread dice: " << folder_stack.top() << endl;
		folder_stack.pop();
	}
	
	return 0;
}