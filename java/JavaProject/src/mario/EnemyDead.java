
package mario;

public class EnemyDead extends Thread {
    Enemy en;

    public EnemyDead(Enemy en) {
        this.en = en;
    }

    public void run() {
        // ������ʱ��ͼƬ�ĳɱ�ѹ���ͼƬ
        en.showImage = StaticValue.allTriangleImage.get(2);
        en.imageType = 2;

        try {// ����һ��ʱ�����Ƴ�
            Thread.sleep(300);
        } catch (InterruptedException e) {

            e.printStackTrace();
        }
        en.bg.getAllEnemy().remove(en);// ���������Ƴ�
        // en.bg.getRemovedEnemy().add(this);
    }

}
