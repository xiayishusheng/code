#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <jni.h>

//================== native methods begin ===================
JNIEXPORT jstring JNICALL native_hello(JNIEnv *env, jclass clazz)
{
    printf("printf hello in c native code.\n");
    return (*env)->NewStringUTF(env, "hello world returned.");
}
//================== native methods ends===================

//指定要注册的类
#define JNIREG_CLASS "com/kaiwen/JniRegister"

/* Table of methods associated with class */
static JNINativeMethod gMethods[] = {
    {"hello", "()Ljava/lang/String;", (void*)native_hello}
};

/* Register native methods for class */
static int registerNativeMethods(JNIEnv* env, const char* className, JNINativeMethod* gMethods, int numMethods)
{
    jclass clazz;
    clazz = (*env)->FindClass(env, className);
    if (clazz == NULL) {
        return JNI_FALSE;
    }
    if ((*env)->RegisterNatives(env, clazz, gMethods, numMethods) < 0) {
        return JNI_FALSE;
    }
    return JNI_TRUE;
}

/* Register native methods for all classes */
static int registerNatives(JNIEnv* env)
{
    if (!registerNativeMethods(env, JNIREG_CLASS, gMethods, sizeof(gMethods) / sizeof(gMethods[0])))
    {
        return JNI_FALSE;
    }
    return JNI_TRUE;
}

/* Returns the JNI version on success, -1 on failure */
JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void* reserved)
{
    JNIEnv* env = NULL;
    jint result = -1;
    if((*vm)->GetEnv(vm, (void**) &env, JNI_VERSION_1_4) != JNI_OK)
    {
        return -1;
    }
    assert(env != NULL);

    if (!registerNatives(env)) {//注册
        return -1;
    }
    // success! return valid version number.
    result = JNI_VERSION_1_4;
    return result;
}

