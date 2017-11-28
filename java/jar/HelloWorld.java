/**
 * 软件名称 命令行打jar包
 * @author zhen
 * @version 1.0
 */
public class HelloWorld {
    /**
     * 主方法，程序入口
     */
    public static void main(String args[]) {

        HelloWorld hw = new HelloWorld();
        hw.print();

        Test test = new Test();
        test.print();

        //System.out.println(strTest());
    }

    /**
     * 打印
     */
    public void print() {
        System.out.println("HelloWorld Test!");
    }

    public static native String strTest();

    static {
        //System.loadLibrary("str");
    }
}

