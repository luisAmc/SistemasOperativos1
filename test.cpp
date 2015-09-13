#include <sys/stat.h>
#include <sys/types.h>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	mkdir("./testFolder", S_IRUSR | S_IWUSR | S_IXUSR);
	return 0;
}