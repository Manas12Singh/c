all: main.exe run clean

main.exe: main.o myThread.o ucontext.o
	gcc -o main.exe main.o myThread.o ucontext.o

main.o: main.c myThread.h
	gcc -c main.c

myThread.o: myThread.c myThread.h
	gcc -c myThread.c

ucontext.o: ucontext.c ucontext.h
	gcc -c ucontext.c

run: main.exe
	./main.exe

clean:
	rm -f main.exe main.o myThread.o ucontext.o