all: build

build:
	ndk-build NDK_PROJECT_PATH=. APP_BUILD_SCRIPT=jni/Android.mk APP_PLATFORM=android-21 #V=1,显示构建命令 ; #NDK_LOG=1,显示NDK构建系统内部日志

push:
	adb push libs/armeabi/chengfa /data/local/tmp/chengfa
	adb push libs/armeabi/demo    /data/local/tmp/demo
	adb shell 'chmod 777 /data/local/tmp/chengfa'
	adb shell 'chmod 777 /data/local/tmp/demo'
run:
	adb shell /data/local/tmp/demo
	adb shell /data/local/tmp/chengfa 5

clean:
	rm -rf libs
	rm -rf obj
