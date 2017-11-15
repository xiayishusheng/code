/*
 *	从键盘读取一个字符串，将0~9的字符放在最后，其他字符放在前面，不改变原有的顺序
 *	例如：输入	hello12345world!
 *	则输出	helloworld!12345
 */

//下面是我自己想的方法，是把字符串中0~9的字符放tempnum，把其他的放在tempchar中，最后把tempnum加到temchar后面。
import java.util.Scanner;

public class ChangeStr {

    @SuppressWarnings("resource")
    public static void main(String args[]) {

        int i=0;
        String originalStr = null;
        String changedStr = null;
        StringBuffer tempCharStr = null;
        StringBuffer tempNumStr = null;

        Scanner scanner = new Scanner(System.in);
        while(scanner.hasNext()) {
            tempCharStr = new StringBuffer();
            tempNumStr = new StringBuffer();
            originalStr = scanner.next();
            if(originalStr.length() > 128) {
                System.out.println("more than 128");
            } else {
                for(i=0; i<originalStr.length(); i++) {
                    if(originalStr.charAt(i) >= '0' && originalStr.charAt(i) <= '9') {
                        tempNumStr.append(originalStr.charAt(i));
                    } else {
                        tempCharStr.append(originalStr.charAt(i));
                    }
                }
            }
            changedStr = tempCharStr.append(tempNumStr).toString();
            System.out.println(changedStr);

            break;
        }
    }
}

