/*
 * =====================================================================================
 *
 *       Filename:  HelloWorld.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2017年11月28日 16时02分02秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include "HelloWorld.h"

JNIEXPORT jstring JNICALL Java_HelloWorld_strTest(JNIEnv * env, jclass thiz)
{
    return (*env)->NewStringUTF(env, "Hello From JNI!!!");
}
