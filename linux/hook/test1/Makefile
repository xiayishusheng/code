CC = gcc -g

all: main hook

main: main.c
	$(CC) -o main main.c
hook: hook.c
	$(CC) -fPIC -shared -o hook.so hook.c -ldl

clean:
	rm -rf main hook.so
