
package mario;

import java.awt.image.BufferedImage;
import java.util.ArrayList;

public class Mario implements Runnable {
    // ����
    private int x, y;
    // ״̬
    private String status;
    // ��ǰ��ʾ������ͼƬ
    private BufferedImage showImage;
    // �������ͷ���
    private int life;
    private int score;
    // �ٶ�
    public int xv = 0;
    // ����һ����ֱ������ٶ�����
    public int yv = 0;
    // �߳�������װRunnable
    private Thread t = null;

    // ��ǰ�ƶ��е�ͼƬ����
    private int moving = 0;
    // ����һ���������󣬱���Mario���ڵĳ���
    private BackGround bg;

    // private MainFrame my;
    // ��Ծ������ʱ��
    private int uptime = 0;
    // ���mario�Ƿ�����
    private boolean isDead = false;
    private boolean isWin = false;
    public ArrayList<Bullet> bullet = new ArrayList<Bullet>(); // �������С���̵߳Ķ���

    // private Bullet bu =new Bullet(this.x,this.y);
    // ���췽��

    public Mario(int x, int y) {
        this.x = x;
        this.y = y;
        // ��ʼ��Mario��ͼƬ
        this.showImage = StaticValue.allMarioImage.get(0);
        this.life = 3;
        this.score = 0;
        t = new Thread(this);
        t.start();

        this.status = "right--standing";
    }

    // �ƶ��ķ���
    public void leftMove() {
        xv = -5;
        if (this.status.indexOf("jumping") != -1) {
            this.status = "left--jumping";
        } else {
            this.status = "left--moving";
        }
    }

    public void rightMove() {
        xv = 5;
        if (this.status.indexOf("jumping") != -1) {
            this.status = "right--jumping";
        } else {
            this.status = "right--moving";
        }
    }

    public void leftStop() {
        xv = 0;
        // �����ǰ�Ѿ�����Ծ״̬�ˣ���ô�Ͳ����ٸı�״̬
        if (this.status.indexOf("jumping") != -1) {
            this.status = "left--jumping";
        } else {
            this.status = "left--standing";
        }
    }

    public void rightStop() {
        xv = 0;
        if (this.status.indexOf("jumping") != -1) {
            this.status = "right--jumping";
        } else {
            this.status = "right--standing";
        }
    }

    public void jump() {// ���ķ���

        if (this.status.indexOf("jumping") == -1) {// ����Ҫ���ڷ���Ծ��״̬���ܹ���
            if (this.status.indexOf("left") != -1) {// �������
                this.status = "left--jumping";
            } else {
                this.status = "right--jumping";
            } // ��ԾӦ�÷�Ϊ�����׶Σ�������ʱ���������С���½���ʱ������������
            yv = -15;
            uptime = 13;
        }
    }

    public void down() {// ����ķ�����1.��Ծ�ĵڶ��׶�Ӧ������2.�߳����е��ϰ���ķ�ΧӦ������
        if (this.status.indexOf("left") != -1) {// �������
            this.status = "left--jumping";// ͬ��Ҳ���ڿ��У�����Ϊjumping״̬
        } else {
            this.status = "right--jumping";
        }
        yv = 15;
    }

    public void dead() {// mario�����ķ���
        // System.out.println("����");
        isDead = true;
        this.xv = 0;
        this.yv = 0;
        this.setX(0);
        this.setY(480);

    }

    public void Win() {// marioʤ���ķ���

        isWin = true;
        this.setX(800);
        this.xv = 0;
        // this.setY(480);

    }

    public void Fall() {// marioʤ���ķ���

        this.setIsDead(true);
        System.out.println("����");
        this.xv = 0;
        this.yv = 0;
        this.setX(0);
        this.setY(480);

    }

    public void shoot() {
        Bullet bu = new Bullet(this.x, this.y, this);
        // System.out.println(bu.x);
        bu.setBg(MainFrame.nowBG);// �������ŵ�bullet���������
        Thread t = new Thread(bu);
        t.start();
        bullet.add(bu);

    }

    // ************************************************����get����*********************************************************************//
    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }

    public String getStatus() {
        return status;
    }

    public BufferedImage getShowImage() {
        return showImage;
    }

    public int getScore() {
        return score;
    }

    public int getLife() {
        return life;
    }

    public boolean getIsDead() {
        return isDead;
    }

    public boolean getIsWin() {
        return isWin;
    }

    public ArrayList<Bullet> getBullet() {
        return bullet;
    }

    // ****************************************************����set����*****************************************************************//

    public void setBg(BackGround bg) {
        this.bg = bg;
    }

    public void setX(int x) {
        this.x = x;
    }

    public void setY(int y) {
        this.y = y;
    }

    public void setIsDead(boolean isDead) {
        this.isDead = isDead;
    }

    // ****************************************************run����*****************************************************************//
    public void run() {
        while (true) {
            // �ж�Mario�Ƿ�������ϰ����������
            // ʹ��forѭ�����ϰ����������
            boolean canLeft = true;
            boolean canRight = true;
            // �����Ƿ����ϰ���֮�ϵı��
            boolean onLand = false;

            for (int i = 0; i < this.bg.getAllObstruction().size(); i++) {
                Obstruction ob = this.bg.getAllObstruction().get(i);
                // �����������ҵ��жϣ����жϷ�Χ��Ϊ50��ģ���жϣ�����Ծ����ô��������
                if (ob.getX() == this.x + 60 && (ob.getY() + 50 > this.y && ob.getY() - 50 < this.y)) {// �ж��ڿ����������������������ҵ����
                    // ���ϰ����Y+60����mario��Y�����ϰ����Y-60С��mario��Y��
                    // ��ʱmario�Ͳ��ܼ������������ƶ���
                    canRight = false;
                }
                if (ob.getX() == this.x - 60 && (ob.getY() + 50 > this.y && ob.getY() - 50 < this.y)) {
                    canLeft = false;
                }
                // ��������״̬��ʾ��ǰ����һ���ϰ��������,�������к͵�����ϰ����ж�
                if (ob.getY() == this.y + 60 && (ob.getX() + 60 > this.x && ob.getX() - 60 < this.x)) {
                    onLand = true;
                }
                // �ж�mario�Ƿ�����Ծ�ж�����һ���ϰ���Ƿ���һ���ϰ�����·�
                // �˴�Ҳ��Ϊ50 ��ֹ���������Ҳ�����ж����ϰ����·��Ѳ��ö��Ķ�����
                if (ob.getY() == this.y - 60 && (ob.getX() + 50 > this.x && ob.getX() - 50 < this.x)) {
                    if (ob.getType() == 0) {// ����ש��
                        // ��ש��ӳ������Ƴ�
                        this.bg.getAllObstruction().remove(ob);
                        // �����Ƴ���ש�鱣�浽һ������֮��
                        this.bg.getRemovedObstruction().add(ob);
                    }
                    if (ob.getType() == 4) {// �����ʺ�
                        ob.setType(2); // ���ʺű�Ϊ����
                        ob.setImage();
                    } else if (ob.getType() == 3) {
                        ob.setType(2);
                        ob.setImage();
                    }

                    uptime = 0;
                }

            }
            // ******************************************�Ƿ��������ײ���ж�***************************************************
            for (int i = 0; i < this.bg.getAllEnemy().size(); i++) {// ȡ�����еĵ���
                Enemy en = this.bg.getAllEnemy().get(i);
                if (en.getX() + 50 > this.x && en.getX() - 50 < this.x && (en.getY() + 50 > this.y && en.getY() - 50 < this.y)) {// �������˵��ж�,����
                    // en.dead();
                    System.out.println("����");
                    this.uptime = 15;
                    yv = -15;
                    try {
                        Thread.sleep(100);
                        this.dead();// ����������
                    } catch (Exception ef) {
                        ef.printStackTrace();
                    }

                }
                if (en.getY() == this.y + 60 && (en.getX() + 60 > this.x && en.getX() - 60 < this.x)) {
                    if (en.getType() == 1) {// �ȵ�Ģ��
                        if (en.imageType != 2) {
                            yv = -15;
                            this.uptime = 7;// ��������һ�ξ���
                        }
                        EnemyDead dead = new EnemyDead(en);
                        dead.start();
                        // en.dead(); //��������
                    } else if (en.getType() == 2) {// �ȵ�ʳ�˻�
                        yv = -10;
                        this.uptime = 15;
                        // en.dead();
                        this.dead();
                    }
                }
            }

            // *******************************�����ذ����µ��ж�****************************************************
            // System.out.println(" ==="+y);
            if (this.y > 600) {

                // this.dead();
            }

            // **********************************************��Ծ���ж�***********************************************************
            if (onLand && uptime == 0) {// �ر�ע��˴�������ǳ�ʼ״̬����ô�Ͳ������else���Ͳ������y������ٶ�
                // ����Ӧ�ü���һ���жϣ��������Ժ�uptime�Ͳ���Ϊ0�ˣ��ͻ�����else{}���ж���ȥ��
                if (this.status.indexOf("left") != -1) {// �������
                    if (xv != 0) {
                        this.status = "left--moving";
                    } else {
                        this.status = "left--standing";
                    }
                } else {
                    if (xv != 0) {
                        this.status = "right--moving";
                    } else {
                        this.status = "right--standing";
                    }
                }

            } else {// ������ڵ�����,���ܽ�����Ծ��״̬
                if (uptime != 0) {// ��ʾ��ǰ��������״̬ʱ
                    uptime--;// ���Ϊ0��ʱ���ֹͣ-��ֻ�а�jump������в��ܽ�����һ��������������һ��
                } else {// ������ֱ����������
                    this.down();// ֱ�ӵ���down ����
                }

                y += yv;// �������������̻����½����̣���һ���ֲ���
            }

            // *********************************************������Ծ���ж�***********************************************************

            // **********************************************�˶�ͼƬ�Ĵ���*********************************************************
            // �ı�����
            if (canLeft && xv < 0 || canRight && xv > 0) {
                x += xv;
                if (x < 0) {// �����ﲻ���ߵ�ǰһ������ȥ
                    x = 0;
                }
            }
            int temp = 0;// ����һ��ͼƬȡ�õĳ�ʼ������
            if (this.status.indexOf("left") != -1) {
                temp += 5;// ���״̬��������Ļ����ͽ���ʼ������+5����Ϊ���ҵ�ͼƬ�±�Ϊ1-5�������Ϊ6-10���˴�û��Ҫд
                // else
            }

            // �ж��Ƿ�ǰΪ�ƶ�
            if (this.status.indexOf("moving") != -1) {
                temp += this.moving;
                moving++;// ע�⣬�˴��������moving���㣬���������Ƶ�+��ȥ���ͻ����Խ����쳣
                if (moving == 4) {
                    moving = 0;
                }

            }
            if (this.status.indexOf("jumping") != -1) {
                temp += 4;
            }
            this.showImage = StaticValue.allMarioImage.get(temp);// �ı���ʾͼƬ
            // Ҫ��������ʱ����Ҫ��������ͼƬһ��һ����ѭ�������״̬Ϊmoving,����ÿ�˶�һ��ͼƬ��Ҫ�ı�һ��

            // *********************************************����***********************************************************

            // �ӵ�����***************************************************************
            // if(this.status.indexOf("left")!=-1){
            // bullet1.setXv(-50);
            // }if(this.status.indexOf("right")!=-1){
            // bullet1.setXv(50);
            // }if(this.status.indexOf("jump")!=-1){
            // bullet1.setYv(-10);
            // }

            try {// ����ʱ��
                Thread.sleep(25);
            } catch (InterruptedException e) {
                // TODO Auto-generated catch block
                e.printStackTrace();
            }

        }
    }
}
