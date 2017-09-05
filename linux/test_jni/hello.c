#include <stdio.h>
#include "jni.h"
#include "JniTest.h"

JNIEXPORT void JNICALL
Java_JniTest_displayHello(JNIEnv *env, jobject obj) 
{
	printf("Hello!\n");
	return;
}
