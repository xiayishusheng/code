<?php											
	$handle=fopen ("many.txt","r");				
		//���ȶ�ȡ��1�У���ȡ��Ϻ�ָ�������һ��
	$buffer=fgets($handle,1024);					//��ȡ��1������
	echo $buffer ."<br>";							
		//���Ž�ָ������ƶ�5���ֽ�
	fseek($handle,6,seek_cup);						//ָ������ƶ�6���ֽ�
		//���Ŷ�ȡһ��
	$buffer=fgets($handle,1024);					//���Ŷ�ȡ��1������
	echo $buffer . "<br>";						
		//��ָ�뷵�ص����ļ���ʼ�����¶�ȡ��1�У���Ϊ�Ǿ���λ��Ϊ0
	fseek($handle,0);								
		//��ȡһ�����ݣ���Ϊָ��ص��ļ���ʼ�����Ի��ȡ��1������
	$buffer=fgets($handle,1024);					//�ٶ�ȡ��1������
	echo $buffer ."<br>";							//�����ȡ����
	fclose ($handle);								//�رմ��ļ�
?>												
