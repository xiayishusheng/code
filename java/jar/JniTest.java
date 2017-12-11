package com.kaiwen;

/**
 * Jni Test
 */
public class JniTest {
    public static void main(String args[]) {
        System.out.println(strFromJni());
    }

    static {
        System.loadLibrary("str");
    }

    public static native String strFromJni();
}

