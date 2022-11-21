CC = gcc
CFLAGS = -Wall -pedantic -ansi -Werror 
OBJ = readFile.o printMap.o buffer.o linkedList.o control.o game.o main.o testdll.o 
EXEC = maze

$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

main.o : main.c main.h 
	$(CC) $(CFLAGS) main.c -c

readFile.o : readFile.c readFile.h
	$(CC) $(CFLAGS) readFile.c -c

printMap.o : printMap.c printMap.h
	$(CC) $(CFLAGS) printMap.c -c

buffer.o : buffer.c 
	$(CC) $(CFLAGS) buffer.c -c

linkedList.o : linkedList.c linkedList.h 
	$(CC) $(CFLAGS) linkedList.c -c

control.o : control.c control.h linkedList.h
	$(CC) $(CFLAGS) control.c -c

game.o : game.c game.h
	$(CC) $(CFLAGS) game.c -c

testdll.o : testdll.c testdll.h
	$(CC) $(CFLAGS) testdll.c -c

clean: 
	rm -f $(EXEC) $(OBJ)
	
