export LD_LIBRARY_PATH=/opt/JniTest:$LD_LIBRARY_PATH
javah JniTest
gcc -shared -fPIC -I/root/work/jdk1.6.0_33/include -I/root/work/jdk1.6.0_33/include/linux hello.c -o libhello.so
