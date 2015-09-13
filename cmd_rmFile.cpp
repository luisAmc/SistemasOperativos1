#include <unistd.h>
#include <iostream>

int main(int argc, char const *argv[]) {
	if (unlink(argv[0]) == 0)
		//std::cout << "\nArchivo eliminado exitosamente\n" << std::endl;
	//else
		//std::cout << "\nHubo un error en la eliminacion del archivo\n" << std::endl;
	return 0;
}