<?php
		/* ����һ�����ó�ʼ����*/
	$host="localhost";						
	$user=��root��;								
	$pass="123456";							
		/* ��������������ݿ������ */
	$link=mysql_connect($host,$user,$pass);		
	if(!$link) echo "ʧ��!<br>";				
	else echo "�ɹ�!<br>";						
		/* ��������ѡ�����ݿ� */
	mysql_select_db("testdb");					
	if(mysql_errno())
	{
		die("<br>".mysql_errno().":".mysql_error()."<br>");				
											
	}
?>
