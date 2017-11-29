#include "JniTest.h"

JNIEXPORT jstring JNICALL Java_JniTest_strFromJni(JNIEnv * env, jclass thiz)
{
    return (*env)->NewStringUTF(env, "Hello From JNI!!!");
}
