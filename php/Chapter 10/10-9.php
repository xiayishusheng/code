<?php									
	$handle=fopen("many.txt","r");			
		//��ȡ����
	$buffer=fgets($handle,1024);			
	echo $buffer ."<br>";					
		//��ȡ�ڶ���
	$buffer=fgets($handle,1024);			
	echo $buffer ."<br>";					
		//��ȡ������
	$buffer=fgets($handle,1024);			
	echo $buffer ."<br>";					
		//��ָ��ص��ļ���ʼ��������ȡ��һ�����ݡ�
	rewind($handle);						
	$buffer=fgets($handle,1024);			
	echo $buffer ."<br>";					
	fclose($handle);						
?>										
