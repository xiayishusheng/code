package com.kaiwen;
public class JniRegister {
    public native String hello();

    static {
        try {
            System.loadLibrary("reg");
        } catch (UnsatisfiedLinkError ule) {
            System.err.println("WARNING: Could not load library!");
        }
    }

    public static void main(String[] args) {
        String s = new JniRegister().hello();
        System.out.println(s);
    }
}
