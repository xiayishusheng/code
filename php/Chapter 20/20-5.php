<?php
		/* ����һ�����ó�ʼ����*/
	$host="localhost";					
	$user=��root��;							
	$pass="123456";						
	$db="students";						
		/* ��������������ݿ������ */
	$link=mysql_connect($host,$user,$pass);	
	if(!$link) echo "ʧ��!<br>";			
	else echo "�ɹ�!<br>";					
		/* ��������ѡ�����ݿ� */
	$ok=mysql_select_db($db);				
	if(!$ok)								
	{
		die("�����ݿ�ʧ��.");				
	}
	else echo "ѡ�����ݿ�ɹ�!<br>";			
?>
