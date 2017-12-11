#include "com_kaiwen_JniTest.h"

JNIEXPORT jstring JNICALL Java_com_kaiwen_JniTest_strFromJni(JNIEnv * env, jclass thiz)
{
    return (*env)->NewStringUTF(env, "Hello From JNI!!!");
}
