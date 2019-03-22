package com.kaiwen;
/**
 * @author zhen
 * @version 1.0
 */

import java.security.SecureRandom;

public class HelloWorld {

    public static void main(String args[]) {
        HelloWorld hw = new HelloWorld();
        hw.print("HelloWorld!");
        String androidId = Long.toHexString(new SecureRandom().nextLong());
        System.out.println(androidId);
    }

    public void print(String msg) {
        System.out.println(msg);
    }
}

