import java.util.Scanner;

public class Xing {
	public static void main(String[] args) {
		int i,j,k,n;
		Scanner input = new Scanner(System.in);
		System.out.print("�����������������");
		n = input.nextInt();
		//���ѭ�����Ʋ���
		for(i=1; i<=n; i++) {
			//��������кţ�����Ǻ���߿ո�
			for(j=1; j<=n-i; j++) {
				System.out.print(" ");
			}
			//��������кţ�����ǺŸ���
			for(k=1; k<=2*i-1; k++) {
				System.out.printf("*");
			}
			//һ�н���������
			System.out.printf("\n");
		}
    }
}