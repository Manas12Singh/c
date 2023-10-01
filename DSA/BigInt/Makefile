#target: dependecy
#	command

a.exe: BigInteger.o main.o
	gcc -o a BigInteger.o main.o
	make clean
	a

main.o: main.c
	gcc -c main.c

BigInteger.o: BigInteger.c
	gcc -c BigInteger.c

clean:
	del BigInteger.o main.o
