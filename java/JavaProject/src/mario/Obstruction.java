
package mario;

import java.awt.image.BufferedImage;
/*
 *�ϰ�����
 * 
 */

public class Obstruction implements Runnable {

    private int x, y; // �ϰ����λ��
    public int yv = 0; // y������ٶ�
    private Thread t = new Thread(this); // ��װ���̶߳���
    private int type; // �ϰ�������࣬��12��
    private int startType; // ĳһλ�ó�ʼ״̬������
    private BufferedImage showImage = null; // ��ʾ��ͼƬ���������ٽ��г�ʼ��
    private boolean inAir = true;
//    private BackGround bg;
    // �߳�������װRunnable

    // ���췽�����ڴ������꣬����

    public Obstruction(int x, int y, int type) {
        this.x = x;
        this.y = y;
        this.type = type;
        setImage();
        t.start();// �ڴ���ʱ�����߳�
    }

    // ���÷���
    public void reset() {

        this.type = startType;
        this.setImage();
    }

    // ����ͼƬ���͸ı���ʾͼƬ,����(type)
    public void setImage() {
        showImage = StaticValue.allObstructionImage.get(type);
    }

    public BufferedImage getShowImage() {
        return showImage;
    }

    // ���е�
    // get����*************************************************************************************
    public int getType() {
        return type;
    }

    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }

    public boolean getInAir() {
        return inAir;
    }
    // ����*************************************************************************************

    // ���е�
    // set����*************************************************************************************
    public void setType(int type) {
        this.type = type;
    }

    public void setYv(int yv) {
        this.yv = yv;
    }

    public void setInAir(boolean inAir) {
        this.inAir = inAir;
    }

    // ����*************************************************************************************
    public void run() {
        // д���̷߳������
        // ��������ʱ��Ҫ�õ�run����
        System.out.println("�����˶���");
        y += yv;
    }

}
