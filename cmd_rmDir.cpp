#include <unistd.h>
#include <iostream>

int main(int argc, char const *argv[]) {
	if (rmdir(argv[0]) == 0)
		//std::cout << "\nDirectorio eliminado exitosamente\n" << std::endl;
	//else
		//std::cout << "\nHubo un error en la eliminacion del directorio\n" << std::endl;
	return 0;
}