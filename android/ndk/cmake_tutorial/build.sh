cd build
cmake .. -DCMAKE_SYSTEM_NAME=Android -DCMAKE_SYSTEM_VERSION=21 -DCMAKE_ANDROID_ARCH_ABI=armeabi-v7a -DCMAKE_ANDROID_NDK=$ANDROID_NDK_PATH -DCMAKE_ANDROID_STL_TYPE=gnustl_static
#cmake .. -DCMAKE_SYSTEM_NAME=Android -DCMAKE_SYSTEM_VERSION=21 -DCMAKE_ANDROID_ARCH_ABI=arm64-v8a -DCMAKE_ANDROID_NDK=$ANDROID_NDK_PATH -DCMAKE_ANDROID_STL_TYPE=gnustl_static

