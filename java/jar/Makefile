include Ext.Makefile

# 获取操作系统
OS_NAME = $(shell uname | tr '[A-Z]' '[a-z]')

all: jar jarjni dex dexjni

jar:
	@echo "\n编译jar:"
	$(call MakeJar)

jarjni:
	@echo "\n编译jarjni:"
	javah -classpath . com.kaiwen.JniTest

ifeq ($(OS_NAME), linux)
	gcc JniTest.c -I${JAVA_HOME}/include -I ${JAVA_HOME}/include/linux -shared -fPIC -o libstr.so
else ifeq ($(OS_NAME), mingw)
	cl -I %JAVA_HOME%\include -I %JAVA_HOME%\include\win32 -LD JniTest.c -Felibstr.dll
endif

dex:
	@echo "\n编译dex:"
	$(call MakeDex)

dexjni:
	@echo "\n编译ndk库:"
	$(call MakeDexJni)

runjar:
	@echo "\n运行jar包:"
	java -jar HelloWorld.jar
	@#java -cp HelloWorld.jar com.kaiwen.HelloWorld

runjarjni:
	@echo "\n运行jarjni:"
	@#java -verbose:jni -Djava.library.path=. com.kaiwen.JniTest
	java -Djava.library.path=. -cp HelloWorld.jar com.kaiwen.JniTest

rundex:
	@echo "\n运行dex:"
	adb push HelloWorld.dex /data/local/tmp
	adb shell dalvikvm -cp  /data/local/tmp/HelloWorld.dex com.kaiwen.HelloWorld

rundexjni:
	@echo "\n运行rundexjni:"
	adb push  out/libs/armeabi/libstr.so /data/local/tmp
	adb shell dalvikvm -Djava.library.path=/data/local/tmp -cp /data/local/tmp/HelloWorld.dex com.kaiwen.JniTest

clean:
	@echo "\n清理文件:"
	rm -rf *.class *.jar *.dex *.so out com
