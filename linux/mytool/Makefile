#main: main.o mytool1.o mytool2.o
#	gcc -o main main.o mytool1.o mytool2.o
#main.o: main.c mytool1.h mytool2.h
#	gcc -c main.c
#mytool1.o: mytool1.c mytool1.h
#	gcc -c mytool1.c
#mytool2.o: mytool2.c mytool2.h
#	gcc -c mytool2.c
#clean:
#	rm -rf main.o
#	rm -rf mytool1.o
#	rm -rf mytool2.o
#	rm -rf main

#main: main.o mytool1.o mytool2.o
#	gcc -o $@ $^
#main.o: main.c mytool1.h mytool2.h
#	gcc -c $<
#mytool1.o: mytool1.c mytool1.h
#	gcc -c $<
#mytool2.o: mytool2.c mytool2.h
#	gcc -c $<
#clean: main main.o mytool1.o mytool2.o
#	rm -rf $^

main: main.o mytool1.o mytool2.o
	gcc -o $@ $^
.c.o:
	gcc -c $<
clean:
	rm -rf main.o
	rm -rf mytool1.o
	rm -rf mytool2.o
	rm -rf main

install:
	cp main /usr/bin
uninstall:
	rm -rf /usr/bin/main
