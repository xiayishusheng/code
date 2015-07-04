
package mario;

import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

import javax.imageio.ImageIO;

/**
 * �������ͼƬ����
 */
public class StaticValue {
    // �����������ͼƬ�Ķ��л���ͼƬ���󣬳�ʼ����д�ڷ�����
    public static List<BufferedImage> allMarioImage = new ArrayList<BufferedImage>();// ����µ�ͼƬ��10
    public static BufferedImage startImage = null;// ��ʼ��ͼƬ
    public static BufferedImage endImage = null;// ������ͼƬ
    public static BufferedImage bgImage = null;// ������ͼƬ
    public static List<BufferedImage> allFlowerImage = new ArrayList<BufferedImage>();// ʳ�˻���ͼƬ��2
    public static List<BufferedImage> allTriangleImage = new ArrayList<BufferedImage>();// �����ֵ�ͼƬ,3
    public static List<BufferedImage> allTurtleImage = new ArrayList<BufferedImage>();// �ڹ��ͼƬ,5
    public static List<BufferedImage> allObstructionImage = new ArrayList<BufferedImage>();// �����ϰ����ͼƬ,12
    public static BufferedImage marioDeadImage = null;// �����������ͼƬ
    public static BufferedImage bulleticon = null;// �ӵ���ͼƬ
    public static String imagePath = System.getProperty("user.dir") + "\\";// ·��

    // System.getProperty("user.dir")+"//bin/";
    // ��ͼƬȫ����ʼ��

    public static void init() {
        // ��ʼ������Mario��ͼƬ
        for (int i = 1; i <= 10; i++) {
            try {
                // System.out.println(System.getProperty("user.dir") + "\\"+ i +
                // ".gif");
                // �����е�ͼƬ��ʼ��������ΪBufferedImage����浽������ȥ��ʹ��ImageIO��read������bufferedImage����ָ��ͼƬ
                allMarioImage.add(ImageIO.read(new File(imagePath + i + ".png")));
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        // ����ͼƬ��ʼ��
        try {

            startImage = ImageIO.read(new File(imagePath + "start.jpg"));
            bgImage = ImageIO.read(new File(imagePath + "firststage.jpg"));

            // System.out.println(System.getProperty(imagePath )+
            // "firststage.jpg");
            endImage = ImageIO.read(new File(imagePath + "firststageend.jpg"));
        } catch (IOException e) {
            e.printStackTrace();
        }
        // ��ʼ�����еĹ���ͼƬ
        for (int i = 1; i <= 5; i++) {
            try {
                if (i <= 2) {
                    allFlowerImage.add(ImageIO.read(new File(imagePath + "flower" + i + ".gif")));
                }
                if (i <= 3) {
                    allTriangleImage.add(ImageIO.read(new File(imagePath + "triangle" + i + ".gif")));
                }
                allTurtleImage.add(ImageIO.read(new File(imagePath + "Turtle" + i + ".gif")));
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        // ��ʼ�����е��ϰ���ͼƬ
        for (int i = 1; i <= 12; i++) {
            try {
                allObstructionImage.add(ImageIO.read(new File(imagePath + "ob" + i + ".gif")));
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        // ��ʼ��Mario������ͼƬ���ӵ�ͼƬ
        try {
            marioDeadImage = ImageIO.read(new File(imagePath + "over.gif"));
            bulleticon = ImageIO.read(new File(imagePath + "bullet.png"));
        } catch (IOException e) {
            e.printStackTrace();
        }

    }

}
