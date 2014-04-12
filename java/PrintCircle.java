
public class PrintCircle {

 /**
  * @param args
  */
 public static void main(String[] args) {
   int n=10;//nԽ�󣬲���Խ�ӽ�Բ
   PrintCircle p = new PrintCircle();
   for(int i=0;i<2*n;i++){
     p.printPoint(n,i);
   }
 }
 
 private int[] getXFromY(int y,int n)//nΪ�뾶��y<2n,����2��x
 {
   if(y<=n){//�ϰ��
     int x1=n-(int)Math.sqrt(n*n-(n-y)*(n-y));
     int x2=(int)Math.sqrt(n*n-(n-y)*(n-y))+n;
     return new int[]{x1,x2};
   }
   else if(y<=2*n){//�°��
     int x1=n-(int)Math.sqrt(n*n-(n-y)*(n-y));
     int x2=(int)Math.sqrt(n*n-(n-y)*(n-y))+n;
     return new int[]{x1,x2};
   }
   return null;
 }
 
 private void printPoint(int n,int y){//�뾶n,��(x,y)��λ�ô�ӡһ��*
     int x1=getXFromY(y,n)[0];
     int x2=getXFromY(y,n)[1];
     for(int i=0;i<=2*n;i++){
       if(i==2*n) System.out.println("\n");
       if(i==x1||i==x2) System.out.print("*");
       else System.out.print(" ");
   }
 }
}
