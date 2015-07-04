
package mario;

public class Bullet implements Runnable {
    // �ӵ�������
    // λ��
    public int x, y;
    // �ٶ�
    public int xv = 50;
    public int yv = 10;
    public int size = 20;
    // private ArrayList<Bullet> bullet;
    private BackGround bg;// �����ӵ����ڵĳ���������ȥ�����е��ϰ���͵���
    private Mario mario;

    public void setBg(BackGround bg) {
        this.bg = bg;

    }

    // ���췽��
    public Bullet(int x, int y, Mario mario) {// ����mario��Ϊ�ˣ����ӵ������ߵ�ʱ�򣬽��ӵ��Ӷ������Ƴ�
        this.x = x;
        this.y = y;
        this.mario = mario;

        // t.start();
    }

    public void setXv(int xv) {
        this.xv = xv;
    }

    public void setYv(int yv) {
        this.yv = yv;
    }

    public void removed() {

    }

    public void run() {
        while (true) {
            x += xv;
            y += yv;

            if (y >= 540) {
                // System.out.println("������");
                // yv=-yv;
                mario.getBullet().remove(this);
            }
            if (y <= 0) {
                // yv=-yv;
                mario.getBullet().remove(this);
            }
            if (x >= 900) {// ���߽����Ƴ�

                mario.getBullet().remove(this);

            }
            if (x <= 0) {// ���߽����Ƴ�

                mario.getBullet().remove(this);
            }

            for (int i = 0; i < this.bg.getAllEnemy().size(); i++) {// ȡ�����еĵ���
                Enemy en = this.bg.getAllEnemy().get(i);
                if (en.getX() + 50 > this.x && en.getX() - 50 < this.x && (en.getY() + 50 > this.y && en.getY() - 50 < this.y)) {// �������˵��ж�,����
                    en.dead();
                    mario.getBullet().remove(this);

                }
                if (en.getY() == this.y + 60 && (en.getX() + 60 > this.x && en.getX() - 60 < this.x)) {
                    if (en.getType() == 1) {// �ȵ�Ģ��

                        en.dead();
                        mario.getBullet().remove(this);
                    } else if (en.getType() == 2) {// �ȵ�ʳ�˻�

                        en.dead();
                        mario.getBullet().remove(this);

                    }
                }
            }

            for (int i = 0; i < this.bg.getAllObstruction().size(); i++) {
                Obstruction ob = this.bg.getAllObstruction().get(i);
                // System.out.println(ob.getX()+"�ϰ���λ��");
                // System.out.println(this.x+"�ӵ�λ��");
                // �����������ҵ��жϣ�
                if (ob.getX() == this.x + 60// ��������
                        && (ob.getY() + 45 > this.y && ob.getY() - 45 < this.y)) {// �ж��ڿ����������������������ҵ����
                    System.out.println("��ײ���ϰ���");

                    if (ob.getType() == 0) {// ����ש��
                        // ��ש��ӳ������Ƴ�
                        mario.getBullet().remove(this);
                        this.bg.getAllObstruction().remove(ob);
                        // �����Ƴ���ש�鱣�浽һ������֮��
                        this.bg.getRemovedObstruction().add(ob);

                    }
                    if (ob.getType() == 4) {// �����ʺ�
                        mario.getBullet().remove(this);
                        ob.setType(2); // ���ʺű�Ϊ����
                        ob.setImage();

                    }
                    if (ob.getType() == 6) {
                        mario.getBullet().remove(this);

                    }
                    if (ob.getType() == 7) {
                        mario.getBullet().remove(this);

                    }
                    if (ob.getType() == 8) {
                        mario.getBullet().remove(this);

                    }
                    if (ob.getType() == 9) {
                        mario.getBullet().remove(this);

                    } else if (ob.getType() == 3) {
                        mario.getBullet().remove(this);
                        ob.setType(2);
                        ob.setImage();
                    }

                }
                if (ob.getX() == this.x - 60// ��������
                        && (ob.getY() + 45 > this.y && ob.getY() - 45 < this.y)) {
                    System.out.println("��ײ���ϰ���");

                    if (ob.getType() == 0) {// ����ש��
                        // ��ש��ӳ������Ƴ�
                        System.out.println("�Ƴ�ש��");
                        mario.getBullet().remove(this);
                        this.bg.getAllObstruction().remove(ob);
                        // �����Ƴ���ש�鱣�浽һ������֮��
                        this.bg.getRemovedObstruction().add(ob);

                    }
                    if (ob.getType() == 4) {// �����ʺ�
                        mario.getBullet().remove(this);
                        System.out.println("�ı��ʺ�");
                        ob.setType(2); // ���ʺű�Ϊ����
                        ob.setImage();

                    }
                    if (ob.getType() == 6) {
                        mario.getBullet().remove(this);

                    }
                    if (ob.getType() == 7) {
                        mario.getBullet().remove(this);

                    }
                    if (ob.getType() == 8) {
                        mario.getBullet().remove(this);

                    }
                    if (ob.getType() == 9) {
                        mario.getBullet().remove(this);

                    } else if (ob.getType() == 3) {
                        mario.getBullet().remove(this);
                        ob.setType(2);
                        ob.setImage();
                    }
                }

                // �ж��ӵ��Ƿ�����Ծ�ж�����һ���ϰ���Ƿ���һ���ϰ�����·�

                // if (ob.getY() == this.y - 60
                // && (ob.getX() + 60 > this.x && ob.getX() - 60 < this.x)) {
                // mario.getBullet().remove(this);
                //
                // if (ob.getType() == 0) {// ����ש��
                // // ��ש��ӳ������Ƴ�
                // this.bg.getAllObstruction().remove(ob);
                // // �����Ƴ���ש�鱣�浽һ������֮��
                // this.bg.getRemovedObstruction().add(ob);
                //
                // }
                // if (ob.getType() == 4) {// �����ʺ�
                // ob.setType(2); // ���ʺű�Ϊ����
                // ob.setImage();
                //
                // }else if(ob.getType() == 3){
                // ob.setType(2);
                // ob.setImage();
                // }
                //
                //
                // }

            }

            try {
                Thread.sleep(50);
            } catch (InterruptedException e) {

                e.printStackTrace();
            }
        }
    }

}
