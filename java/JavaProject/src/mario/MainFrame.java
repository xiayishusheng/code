
package mario;

import java.awt.Graphics;
import java.awt.Toolkit;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.image.BufferedImage;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

import javax.swing.JFrame;
import javax.swing.JOptionPane;

/**
 * ������
 * 
 * @author gdk qq:515037030
 */
@SuppressWarnings("static-access")
public class MainFrame extends JFrame implements KeyListener, Runnable {
    private static final long serialVersionUID = -7670737514294745294L;

    private Thread t = new Thread(this);
    // private boolean isStart = false;// �Ƿ��Ѿ���ʼ��һ��ʼ��Ϸ�ǲ��Ὺʼ��

    private List<BackGround> allBG = new ArrayList<BackGround>();// ��ű���ͼƬ�Ķ���
    public static BackGround nowBG = null;// ��ǰ����ͼƬ���������ٽ��г�ʼ��

    public BackGround getNowBg() {
        return nowBG;

    }

    private Mario mario = null;
    private Bullet bullet1 = null;

    // ArrayList<Bullet> bullet=null; //����ӵ��Ķ���

    public static void main(String args[]) {
        MainFrame ui = new MainFrame();
        ui.initUI();

    }

    public void initUI() {
        this.setTitle("С����´�������");
        this.setSize(900, 600);
        this.addKeyListener(this);
        this.setDefaultCloseOperation(3);
        t.start();
        int width = Toolkit.getDefaultToolkit().getScreenSize().width;
        int height = Toolkit.getDefaultToolkit().getScreenSize().height;
        this.setLocation((width - 900) / 2, (height - 600) / 2);
        StaticValue.init();// �ڴ�������֮ǰ�ͳ�ʼ��ȫ����ͼƬ
        this.setVisible(true);
        // ����ȫ���ĳ���
        for (int i = 1; i <= 4; i++) {
            this.allBG.add(new BackGround(i, i == 4 ? true : false));
            // ��BackGround�е�ͼƬ�±���������iΪ����������flagΪtrue���������Ϊfalse,Ȼ��ӵ���ǰ��allBG��������
        }
        // ����һ����������Ϊ��ǰ����
        this.nowBG = this.allBG.get(0);
        this.mario = new Mario(0, 480);// ����³�ʼ��
        // this.bullet1 =new Bullet(mario.getX(),mario.getY());

        // ����������mario�����������ȥ
        this.mario.setBg(nowBG);// ���ڳ�����ȫ�����ϰ���Ϳ���ȡ����
        // this.bullet1.setBg(nowBG);//ȡ��ȫ���ĵ���
        this.setResizable(false);

    }

    public void keyPressed(KeyEvent e) {
        if (e.getKeyCode() == 39) {// ���������
            System.out.println("ִ����");
            mario.rightMove();
        }
        if (e.getKeyCode() == 37) {// ���������
            mario.leftMove();
        }
        if (e.getKeyCode() == 38) {// �������Ծ
            mario.jump();
        }
        if (e.getKeyCode() == 32) {// ����·����ӵ�
            mario.shoot();
        }

    }

    public void keyReleased(KeyEvent e) {
        if (e.getKeyCode() == 39) {// ���������
            mario.rightStop();
        }
        if (e.getKeyCode() == 37) {// ���������
            mario.leftStop();
        }
    }

    public void keyTyped(KeyEvent e) {
        // ����//

    }

    public void paint(Graphics g) {
        // ����߳�������Χʱ���л�����
        if (this.mario != null) {
            List<Obstruction> obt = this.nowBG.getAllObstruction();
            // ȡ�����е��ϰ���
            for (int i = 0; i < obt.size(); i++) {
                Obstruction obs = obt.get(i);
                // if(obs.getType()==9){
                if (this.nowBG.getSort() == 1) {
                    // System.out.println(this.nowBG.getSort());
                    if (this.mario.getX() >= 0) {
                        System.out.println(this.mario.getX());
                        obs.setYv(10);
                        System.out.println("");
                        // System.out.println(obs.yv);
                    }
                }
                // }
            }
            //
            // ʹ��˫���弼������ֹg�ķ�������
            BufferedImage image = new BufferedImage(900, 600, BufferedImage.TYPE_3BYTE_BGR);// ��������ͼƬ
            Graphics g2 = image.getGraphics();// �ӻ���ͼƬ�����ȡ����
            g2.drawImage(this.nowBG.getBgImage(), 0, 0, this);// ��ͼƬ���ڴ�������

            // ���Ƶ���
            Iterator<Enemy> iter1 = this.nowBG.getAllEnemy().iterator();// ʹ�õ��������б���
            while (iter1.hasNext()) {
                Enemy en = iter1.next();
                g2.drawImage(en.getShowImage(), en.getX(), en.getY(), this);
            }
            // �����ϰ���
            Iterator<Obstruction> iter = this.nowBG.getAllObstruction().iterator();// ʹ�õ��������б���
            while (iter.hasNext()) {
                Obstruction ob = iter.next();
                g2.drawImage(ob.getShowImage(), ob.getX(), ob.getY(), this);
            }
            // ��Mario����ȥ
            g2.drawImage(this.mario.getShowImage(), this.mario.getX(), this.mario.getY(), this);

            // ���ӵ�
            // this.bullet=mario.getBullet();
            for (int i = 0; i < mario.bullet.size(); i++) {
                bullet1 = mario.bullet.get(i);
                // bullet1.setBg(nowBG);//ȡ��ȫ���ĵ���
                if (mario.getStatus().indexOf("left") != -1) {
                    bullet1.setXv(-50);
                }
                if (mario.getStatus().indexOf("right") != -1) {
                    bullet1.setXv(50);
                }
                if (mario.getStatus().indexOf("jump") != -1) {
                    // bullet1.setYv(-10);
                }
                // Bullet bullets = bullet.get(i);
                // g2.setColor(Color.red);
                // g2.fillOval( bullets.x-20, bullets.y-30, bullets.size,
                // bullets.size);
                g2.drawImage(StaticValue.bulleticon, bullet1.x, bullet1.y, this);
            }

            // //��������
            // for(int i=0;i<10;i++){
            // g2.drawLine(0, 60*i, 900, 60*i);
            // }
            // for(int i=0;i<15;i++){
            // g2.drawLine(60*i, 0, 60*i, 600);
            // }

            // �ѻ���ͼƬ���Ƶ������Ĵ�����
            g.drawImage(image, 0, 0, this);
        }

    }

    public void run() {
        while (true) {
            this.repaint();

            try {
                if (this.mario != null) {
                    if (this.mario.getX() >= 840) {
                        this.nowBG = this.allBG.get(this.nowBG.getSort());
                        this.mario.setBg(this.nowBG);
                        if (this.nowBG.getSort() == 3) {
                            this.mario.setX(75);
                            this.mario.setY(0);
                        } else {
                            this.mario.setX(0);
                        }

                    }
                    if (mario.getY() == 600) {
                        // mario.setIsDead(true);
                        // this.mario.setX(0);
                        // this.mario.setY(480);
                        // this.mario.xv=0;
                        // this.mario.yv=0;
                        this.mario.Fall();
                    }
                    if (this.nowBG.getSort() == 4) {
                        if (this.mario.getX() == 700) {
                            this.mario.Win();
                            if (this.mario.getIsWin() == true) {
                                JOptionPane.showMessageDialog(this, "�����ˣ��������");
                            }
                        }
                    }

                    if (mario.getIsDead() == true) {
                        JOptionPane.showMessageDialog(this, "������");
                        mario.setIsDead(false);

                    }

                }
                Thread.sleep(25);

            } catch (InterruptedException e) {

                e.printStackTrace();
            }
        }

    }

}
