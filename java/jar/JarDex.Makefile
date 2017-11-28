#命令行方式打jar包
define MakeJar
    javac HelloWorld.java
    jar cfvm HelloWorld.jar Manifest.txt *.class
    @#jar cfvM HelloWorld-NoManifest.jar *.class #生成无清单文件的jar包
endef

#打包成dex文件
define MakeDex
    @#${HOME}/android/android-sdk/build-tools/26.0.2/dx --dex --output=Hello.dex Hello.jar
    dx --dex --output=HelloWorld.dex HelloWorld.jar
    adb push HelloWorld.dex /data/local/tmp
    adb shell dalvikvm -cp /data/local/tmp/HelloWorld.dex HelloWorld
endef

