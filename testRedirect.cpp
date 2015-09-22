#include <stdio.h>
using namespace std;

int main(int argc, char const *argv[]){
	FILE *result_file;
	printf("Pal stdout\n");
	result_file = freopen("file.txt", "w+", stdout);
	printf("Pal archivo");
	fclose(result_file);
	return 0;
}