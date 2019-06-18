CC = gcc -g

test: main.c hook.so
	$(CC) -o test main.c
hook.so: hook.c
	$(CC) -fPIC -shared -o hook.so hook.c -ldl
clean:
	rm -rf test hook.so
