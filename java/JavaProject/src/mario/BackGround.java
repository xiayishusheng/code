
package mario;

import java.awt.image.BufferedImage;
import java.util.ArrayList;
import java.util.List;

public class BackGround {
    private BufferedImage bgImage = null;// ��ǰ�ı���
    private int sort;// ��ǰ�ĳ�������������������������˳��
    private boolean flag;// ���flagΪtrue����Ϊ���һ������

    // ���幹�췽���������������ʼ������ͼƬ
    private List<Enemy> allEnemy = new ArrayList<Enemy>();// ȫ���ĵ��˶���
    private List<Obstruction> allObstruction = new ArrayList<Obstruction>();// ȫ�����ϰ������
    private List<Enemy> removedEnemy = new ArrayList<Enemy>();// ������ĵ��˶���
    private List<Obstruction> removedObstruction = new ArrayList<Obstruction>();// ��������ϰ������
    private List<Bullet> allBullet = new ArrayList<Bullet>();// ȫ�����ӵ�����

    public BackGround(int sort, boolean flag) {

        this.sort = sort;
        this.flag = flag;
        if (flag) {// �����
            bgImage = StaticValue.endImage;
        } else {
            bgImage = StaticValue.bgImage;// ��Ϸ����
        }

        if (sort == 1) {
            for (int i = 0; i < 15; i++) {// ���ϰ����еĵذ����ӵ������е��ϰ����������
                // if(i!=4&i!=5){
                Obstruction ob = new Obstruction(i * 60, 540, 9);
                ob.setInAir(false);
                this.allObstruction.add(ob);

                // }
            }
            // this.allObstruction.add(new Obstruction(420,480,4));
            this.allObstruction.add(new Obstruction(120, 360, 4));
            this.allObstruction.add(new Obstruction(300, 360, 0));
            this.allObstruction.add(new Obstruction(360, 360, 4));
            this.allObstruction.add(new Obstruction(420, 360, 0));
            this.allObstruction.add(new Obstruction(480, 360, 4));
            this.allObstruction.add(new Obstruction(540, 360, 0));
            this.allObstruction.add(new Obstruction(420, 180, 4));
            this.allObstruction.add(new Obstruction(660, 540, 6));
            this.allObstruction.add(new Obstruction(720, 540, 5));
            this.allObstruction.add(new Obstruction(660, 480, 8));
            this.allObstruction.add(new Obstruction(720, 480, 7));

            this.allObstruction.add(new Obstruction(660, 120, 4));

            this.allObstruction.add(new Obstruction(660, 300, 3));// ��������ɫ��

            // �������

            this.allEnemy.add(new Enemy(600, 480, true, 1, this));// ͬʱ����ǰ���������˵��˵�����

            this.allEnemy.add(new Enemy(690, 540, true, 2, 420, 540, this));

            // this.allEnemy.add(new Enemy(60,540,true,2,420,540,this));
            // this.allEnemy.add(new Enemy(120,540,true,2,420,540,this));
            // this.allEnemy.add(new Enemy(180,540,true,2,240,540,this));
            // this.allEnemy.add(new Enemy(240,540,true,2,420,540,this));
            // this.allEnemy.add(new Enemy(300,540,true,2,240,540,this));
            // this.allEnemy.add(new Enemy(360,540,true,2,420,540,this));

        }
        if (sort == 2) {// �ڶ�������
            for (int i = 0; i < 15; i++) {// ���ϰ����еĵذ����ӵ������е��ϰ����������
                // if(i!=10&i!=11){

                Obstruction ob = new Obstruction(i * 60, 540, 9);
                ob.setInAir(false);
                this.allObstruction.add(ob);
                // }
            }
            this.allObstruction.add(new Obstruction(60, 540, 6));// ��һ��ˮ��
            this.allObstruction.add(new Obstruction(120, 540, 5));
            this.allObstruction.add(new Obstruction(60, 480, 6));
            this.allObstruction.add(new Obstruction(120, 480, 5));
            this.allObstruction.add(new Obstruction(60, 420, 8));
            this.allObstruction.add(new Obstruction(120, 420, 7));

            this.allObstruction.add(new Obstruction(240, 540, 6));// �ڶ���ˮ��
            this.allObstruction.add(new Obstruction(300, 540, 5));
            this.allObstruction.add(new Obstruction(240, 480, 6));
            this.allObstruction.add(new Obstruction(300, 480, 5));
            this.allObstruction.add(new Obstruction(240, 420, 6));
            this.allObstruction.add(new Obstruction(300, 420, 5));
            this.allObstruction.add(new Obstruction(240, 360, 8));
            this.allObstruction.add(new Obstruction(300, 360, 7));
            this.allEnemy.add(new Enemy(600, 480, true, 1, this));
        }
        if (sort == 3) {
            for (int i = 0; i < 15; i++) {// ���ϰ����еĵذ����ӵ������е��ϰ����������
                Obstruction ob = new Obstruction(i * 60, 540, 9);
                ob.setInAir(false);
                this.allObstruction.add(ob);
            }
            this.allObstruction.add(new Obstruction(240, 540, 6));// �ڶ���ˮ��
            this.allObstruction.add(new Obstruction(300, 540, 5));
            this.allObstruction.add(new Obstruction(240, 480, 6));
            this.allObstruction.add(new Obstruction(300, 480, 5));
            this.allObstruction.add(new Obstruction(240, 420, 6));
            this.allObstruction.add(new Obstruction(300, 420, 5));
            this.allObstruction.add(new Obstruction(240, 360, 8));
            this.allObstruction.add(new Obstruction(300, 360, 7));

            this.allEnemy.add(new Enemy(240, 480, true, 1, this));
            this.allEnemy.add(new Enemy(240, 480, true, 1, this));
            this.allEnemy.add(new Enemy(300, 480, true, 1, this));
            this.allEnemy.add(new Enemy(540, 480, true, 1, this));
            this.allEnemy.add(new Enemy(540, 480, true, 1, this));
            this.allEnemy.add(new Enemy(600, 480, true, 1, this));
            this.allEnemy.add(new Enemy(600, 480, true, 1, this));
            this.allEnemy.add(new Enemy(120, 480, true, 1, this));
        }
        if (sort == 4) {
            for (int i = 0; i < 15; i++) {// ���ϰ����еĵذ����ӵ������е��ϰ����������
                Obstruction ob = new Obstruction(i * 60, 540, 9);
                ob.setInAir(false);
                this.allObstruction.add(ob);
            }
            this.allEnemy.add(new Enemy(240, 480, true, 1, this));
            this.allEnemy.add(new Enemy(540, 480, true, 1, this));
            this.allEnemy.add(new Enemy(120, 480, true, 1, this));
        }
    }

    // һЩ get����*****************************************************************
    // ��ȡ��ǰ����ͼƬ�ķ�����
    public BufferedImage getBgImage() {
        return bgImage;
    }

    // ȡ�������ϰ���ķ���
    public List<Obstruction> getAllObstruction() {
        return allObstruction;
    }

    public List<Enemy> getAllEnemy() {
        return allEnemy;
    }

    public List<Enemy> getRemovedEnemy() {
        return removedEnemy;
    }

    // ��ñ��Ƴ����ϰ���ķ���
    public List<Obstruction> getRemovedObstruction() {
        return removedObstruction;
    }

    public int getSort() {
        return sort;
    }

    // һЩ get����*****************************************************************

    // ���÷����������е��ϰ���͵��˷��ص�ԭ�����꣬������״̬Ҳ�޸�
    public void reset() {

    }
}
