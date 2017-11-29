#命令行方式打jar包
define MakeJar
    javac *.java
    jar cfvm HelloWorld.jar Manifest.txt *.class
    @#jar cfvM HelloWorld-NoManifest.jar *.class #生成无清单文件的jar包
endef

#打包成dex文件
define MakeDex
    dx --dex --output=HelloWorld.dex HelloWorld.jar
    ndk-build NDK_PROJECT_PATH=out APP_BUILD_SCRIPT=./Android.mk APP_PLATFORM=android-21
endef

