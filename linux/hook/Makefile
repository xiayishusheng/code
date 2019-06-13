test: main.c hook.so
	gcc -o test main.c
hook.so: hook.c
	gcc -fPIC -shared -o hook.so hook.c -ldl
