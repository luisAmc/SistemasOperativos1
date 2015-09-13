#include <sys/stat.h>
#include <iostream>
#include <sys/types.h>

int main(int argc, char const *argv[]) {
	if (mkdir(argv[0], S_IRUSR | S_IWUSR | S_IXUSR) == 0)
		//std::cout << "\nDirectorio creado exitosamente\n" << std::endl;
	else
		//std::cout << "\nHubo un error en la creacion del directorio\n" << std::endl;
	return 0;
}