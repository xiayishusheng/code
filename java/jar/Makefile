include JarDex.Makefile

# 获取操作系统
OS_NAME = $(shell uname | tr '[A-Z]' '[a-z]')

jar:
	$(call MakeJar)

dex:
	$(call MakeDex)

jni: jar
ifeq ($(OS_NAME), linux)
	javah -classpath . HelloWorld
	gcc HelloWorld.c -I${JAVA_HOME}/include -I ${JAVA_HOME}/include/linux -shared -fPIC -o libstr.so
else ifeq ($(OS_NAME), cygwin)
	@echo "==="
else ifeq ($(OS_NAME), mingw)
	@echo "---"
endif

runjar: jar
	@echo "\n运行jar包:"
	java -jar HelloWorld.jar
	java -Djava.library.path=. HelloWorld
	@#java -cp HelloWorld-NoManifest.jar HelloWorld

clean:
	rm -rf *.class
	rm -rf *.jar
	rm -rf *.dex
	rm -rf *.so
