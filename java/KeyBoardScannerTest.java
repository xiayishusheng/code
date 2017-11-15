import java.util.Scanner;

public class KeyBoardScannerTest {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		//把回车最为分隔符
		//sc.useDelimiter("\n");
		while(sc.hasNext()) {
			//输出输入项
			System.out.println("键盘输入的内容是：" + sc.next());
		}
	}
}