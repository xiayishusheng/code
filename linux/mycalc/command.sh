gcc -fPIC -shared calc.c -o libcalc.so
gcc main.c -L . -ldl -o calc
