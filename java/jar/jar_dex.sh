#命令行方式打jar包:
javac HelloWorld.java
jar cfvm HelloWorld.jar Manifest.txt HelloWorld.class Test.class
java -jar HelloWorld.jar

echo "======"

#打包成dex文件
jar cfvM Hello.jar HelloWorld.class Test.class #不生成清单文件
#dx --dex --output=Hello.dex.jar Hello.jar
${HOME}/android/android-sdk/build-tools/26.0.2/dx --dex --output=Hello.dex Hello.jar
adb push Hello.dex /data/local/tmp
adb shell dalvikvm -cp /data/local/tmp/Hello.dex HelloWorld

