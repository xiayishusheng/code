<?php
		/* ����һ�����ó�ʼ����*/
	$host="localhost";					
	$user="root";							
	$pass="123456";						
		/* �����������MySQL������ */
	$link=mysql_connect($host,$user,$pass);	
	if(!$link) echo "����ʧ��!<br>";		
	else echo "���ӳɹ�!<br>";				
		/*���������ر����ݿ�*/
	$close=mysql_close();					
	if($close)							
	{
	echo "�Ͽ����ݿ�����!";					
	}
?>
