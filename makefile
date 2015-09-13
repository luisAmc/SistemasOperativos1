Main: Main.o cmd_mkDir cmd_rmDir cmd_rmFile cmd_rmDirR
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

cmd_rmDirR: cmd_rmDirR.o
	g++ cmd_rmDirR.o -o cmd_rmDirR

cmd_rmDirR.o: cmd_rmDirR.cpp
	g++ -c cmd_rmDirR.cpp

cmd_rmFile: cmd_rmFile.o
	g++ cmd_rmFile.o -o cmd_rmFile

cmd_rmFile.o: cmd_rmFile.cpp
	g++ -c cmd_rmFile.cpp

clean:
	rm *.o

clean all:
	rm *.o Main cmd_mkDir cmd_rmDir cmd_rmFile cmd_rmDirR