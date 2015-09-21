Main: MainP.o chmod uname cat ln cmd_mkDir cmd_rmDir cmd_rmFile cmd_rmDirR ps kill
	g++ MainP.cpp -o Main
MainP.o: MainP.cpp
	g++ -c MainP.cpp
chmod: chmod.o
	g++ chmod.cpp -o chmod
chmod.o: chmod.cpp
	g++ -c chmod.cpp
uname: uname.o
	g++ uname.cpp -o uname
uname.o: uname.cpp
	g++ -c uname.cpp
cat:	cat.o
	g++ cat.cpp -o cat
cat.o:	cat.cpp
	g++ -c cat.cpp
ln:	ln.o
	g++ ln.cpp -o ln
ln.o:	ln.cpp
	g++ -c ln.cpp
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

ps:	ps.o
	g++ ps.cpp -o ps
ps.o:
	g++ -c ps.cpp
kill:	kill.o
	g++ kill.cpp -o kill
kill.o:
	g++ -c kill.cpp
clean:
	rm *.o
