
package mario;

import java.awt.image.BufferedImage;

/**
 * ������ qq:515037030
 */
public class Enemy implements Runnable {

    private int x;
    private int y;
    private int yv = 0;
    private int startX;// ��ʾ������
    private int startY;
    private int type;// ����
    public BufferedImage showImage;// ͼƬ����������
    private boolean isLeftOrUP = true;
    private MainFrame my;
    // �ƶ��ķ�Χ
    private int upMax = 0;
    private int downMax = 0;

    private Thread t = new Thread(this);
    // ���峡��������ȡ�����е��ϰ���
    public BackGround bg;

    // ����ͼƬ״̬
    public int imageType = 0;

    // public void setBg(BackGround bg) {//����ǰ�����ӵ������������еķ���
    // this.bg = bg;
    // }

    // ���췽��
    // ��ͬ�ĵ����в�ͬ�Ĺ��췽��
    public Enemy(int x, int y, boolean isLeft, int type, BackGround bg) {// ����Ģ��(��ͨ����)
        this.x = x;
        this.y = y;
        this.startX = x;
        this.startY = y;
        this.isLeftOrUP = isLeft;
        this.type = type;
        this.bg = bg;
        if (type == 1) {
            this.showImage = StaticValue.allTriangleImage.get(0);// ȡĢ���ĵ�һ��ͼƬ
            if (x == 0) {

            }
        }
        t.start();
    }

    public Enemy(int x, int y, boolean isUp, int type, int upMax, int downMax, BackGround bg) {// ʳ�˻�
        this.x = x;
        this.y = y;
        this.startX = x;
        this.startY = y;
        this.isLeftOrUP = isUp;
        this.type = type;
        this.upMax = upMax;
        this.downMax = downMax;
        this.bg = bg;
        if (type == 2) {
            this.showImage = StaticValue.allFlowerImage.get(0);// ȡʳ�˻��ĵ�һ��ͼƬ
        }
        t.start();
    }

    // ��run������ȥ���������ƶ�
    public void run() {

        while (true) {

            boolean canLeft = true;
            boolean canRight = true;
            boolean onLand = false;

            if (type == 1) {// ����Ģ�����ƶ�����
                if (this.isLeftOrUP) { // ����
                    this.x -= 2;// �����ٶȣ���mario����
                } else { // ����
                    this.x += 2;
                }
                if (imageType == 0) {// �н��л�ͼ
                    // System.out.println(imageType);
                    imageType = 1;
                } else if (imageType == 1) {
                    imageType = 0;
                }

                for (int i = 0; i < this.bg.getAllObstruction().size(); i++) {
                    Obstruction ob = this.bg.getAllObstruction().get(i);
                    if (ob.getX() == this.x + 60 && (ob.getY() + 50 > this.y && ob.getY() - 50 < this.y)) {
                        canRight = false;
                    }
                    if (ob.getX() == this.x - 60 && (ob.getY() + 50 > this.y && ob.getY() - 50 < this.y)) {
                        canLeft = false;
                    }
                    if (ob.getInAir() == false) {// ȡ�ذ�

                        // �������û��վ���ϰ����Ͼ͵���
                        if (ob.getY() == this.y + 60 && ((ob.getX() + 60 > this.x && ob.getX() - 60 < this.x))) {
                            onLand = true;
                            // break;
                        }
                    }
                }
                if (onLand) {// ������ڵ���,�ر�ע��˴����ܽ��ж�onLand�ķ����͸ı�Y����ľ���д��һ����ΪҪ���ϰ�����б������ҵ�һ��ʹOnLandΪfalse�Ĳ�ִ�иı�Y����ľ���
                    yv = 0;
                } else if (!onLand) {
                    yv = 10;
                    y += yv;
                }

                // System.out.println("��ǰ�н�״̬"+this.isLeftOrUP);
                if (this.isLeftOrUP && !canLeft || this.x == 0) {// ���������ϰ��������ߣ����������ϰ��������ߣ����߷���

                    this.isLeftOrUP = false;
                    // System.out.println("�����ϰ�����"+this.isLeftOrUP);
                } else if (!this.isLeftOrUP && !canRight || this.x == 840) {

                    this.isLeftOrUP = true;
                }
                this.showImage = StaticValue.allTriangleImage.get(imageType);
            }
            if (type == 2) {// ����ʳ�˻����ƶ�����
                if (this.isLeftOrUP) {
                    this.y -= 2;
                } else {

                    this.y += 4;
                }
                if (imageType == 0) {
                    imageType = 1;
                } else {
                    imageType = 0;
                }
                if (this.isLeftOrUP && this.y == this.upMax) {
                    this.isLeftOrUP = false;
                }
                if (!this.isLeftOrUP && this.y == this.downMax) {
                    this.isLeftOrUP = true;
                }
                this.showImage = StaticValue.allFlowerImage.get(imageType);
            }

            try {
                Thread.sleep(50);
            } catch (InterruptedException e) {

                e.printStackTrace();
            }
        }

    }

    public void reset() {

    }

    public void dead() {// ���������ķ���
        // ������ʱ��ͼƬ�ĳɱ�ѹ���ͼƬ
        this.showImage = StaticValue.allTriangleImage.get(2);
        imageType = 2;
        this.bg.getAllEnemy().remove(this);// ���������Ƴ�
        this.bg.getRemovedEnemy().add(this);
    }

    // public void setImage(){
    // showImage=StaticValue.allTriangleImage.get(type);
    // }
    public int getType() {
        return type;
    }

    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }

    public BufferedImage getShowImage() {
        return showImage;
    }
}
