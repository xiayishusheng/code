import java.util.Scanner;

public class KeyBoardScannerTest {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		//�ѻس���Ϊ�ָ���
		//sc.useDelimiter("\n");
		while(sc.hasNext()) {
			//���������
			System.out.println("��������������ǣ�" + sc.next());
		}
	}
}