Main: Main.o cmd_mkDir cmd_rmDir
	g++ Main.o -o Main -lpthread

Main.o: Main.cpp
	g++ -c Main.cpp -lpthread

cmd_mkDir: cmd_mkDir.o
	g++ cmd_mkDir.o -o cmd_mkDir

cmd_mkDir.o: cmd_mkDir.cpp
	g++ -c cmd_mkDir.cpp

cmd_rmDir: cmd_rmDir.o
	g++ cmd_rmDir.o -o cmd_rmDir

cmd_rmDir.o: cmd_rmDir.cpp
	g++ -c cmd_rmDir.cpp

clean:
	rm *.o

clean all:
	rm *.o Main cmd_mkDir cmd_rmDir