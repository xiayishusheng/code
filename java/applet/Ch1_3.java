    import java.applet.*;  
    import java.awt.*;  
     
    public class Ch1_3 extends Applet   
    {  
        int x,y;  
          
        public void paint(Graphics g)   
        {  
            //����֮ǰ��������ȡ�û���  
            //Graphics g=getGraphics();  
             //��x�ᡢy��  
            for(x=0;x<=750;x+=1)  
            {  
                g.drawString(".",x,200);  
                if(x<=385) g.drawString(".",360,x);  
            }  
            g.drawString("Y",330,20);  
             //��y���ͷ  
            for(x=360;x<=370;x+=1)  
            {  
                g.drawString(".",x-10,375-x);  
                g.drawString(".",x,x-355);  
            }  
             //��x���ͷ  
            g.drawString("X",735,230);  
            for(x=740;x<=750;x+=1)  
            {  
                g.drawString(".",x,x-550);  
                g.drawString(".",x,950-x);  
            }  
             //��cox()����  
            for(x=0;x<=720;x+=1)  
            {  
                double a=Math.cos(x*Math. PI/180+Math.PI);  
                y=(int)(200+80*a);              //�Ŵ�80��������ƽ��200������  
                g.drawString(".",x,y);  
            }  
        }  
    }  