#设置环境变量
#export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:.
#export ANDROID_NDK=${HOME}/android/android-ndk-r10e
#export PATH=${ANDROID_NDK}:${HOME}/android/android-sdk/build-tools/26.0.2:${PATH}

#生成jar包
define MakeJar
    javac *.java -d .
    jar cfvm HelloWorld.jar manifest.txt com
    @#jar cfvM HelloWorld-NoManifest.jar com #生成无清单文件的jar包
endef

#转换为dex
define MakeDex
    dx --dex --output=HelloWorld.dex HelloWorld.jar
endef

#编译ndk库
define MakeDexJni
    ndk-build NDK_PROJECT_PATH=out APP_BUILD_SCRIPT=./Android.mk APP_PLATFORM=android-21
endef

