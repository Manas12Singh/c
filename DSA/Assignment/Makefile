#target: dependency
#	command

a.exe: mystack.o main.o
	gcc -o a mystack.o main.o
	make clean
	a

main.o: main.c
	gcc -c main.c

mystack.o: mystack.c
	gcc -c mystack.c

clean:
	del mystack.o main.o
