include JarDex.Makefile

# 获取操作系统
OS_NAME = $(shell uname | tr '[A-Z]' '[a-z]')

all: jar dex jni

jar:
	@echo "\n编译jar:"
	$(call MakeJar)

dex:
	@echo "\n编译dex:"
	$(call MakeDex)

jni:
	@echo "\n编译jni:"
	$(call MakeDex)
	javah -classpath . JniTest
ifeq ($(OS_NAME), linux)
	gcc JniTest.c -I${JAVA_HOME}/include -I ${JAVA_HOME}/include/linux -shared -fPIC -o libstr.so
else ifeq ($(OS_NAME), mingw)
	cl -I %JAVA_HOME%\include -I %JAVA_HOME%\include\win32 -LD JniTest.c -Felibstr.dll
endif

runjar:
	@echo "\n运行jar包:"
	java -jar HelloWorld.jar
	@#java -cp HelloWorld.jar HelloWorld

runjni:
	@echo "\n运行jni:"
	@#java -verbose:jni -Djava.library.path=. JniTest
	java -Djava.library.path=. -cp HelloWorld.jar JniTest

rundex:
	@echo "\n运行dex:"
	adb push HelloWorld.dex /data/local/tmp
	adb push ./out/libs/armeabi/libstr.so /data/local/tmp
	adb shell dalvikvm -cp  /data/local/tmp/HelloWorld.dex HelloWorld
	adb shell dalvikvm -Djava.library.path=/data/local/tmp -cp /data/local/tmp/HelloWorld.dex JniTest

clean:
	@echo "\n清理:"
	rm -rf *.class *.jar *.dex *.so out
