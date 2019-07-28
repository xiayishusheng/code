CC = gcc -g

all: main myhook main2

main: main.c
	$(CC) -o main main.c
myhook: myhook.c
	$(CC) -fPIC -shared -o myhook.so myhook.c -ldl
main2: main.c
	$(CC) -o main2 main.c -fno-builtin-strcmp

clean:
	rm -rf main myhook.so main2
