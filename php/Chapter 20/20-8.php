<?php
		/* ����һ�����ó�ʼ����*/
	$host="localhost";							
	$user=��root��;									
	$password=��123456��;							
		/* ��������������ݿ������ */
	$conn=mysql_connect($host,$user,$password)  or	
	die ("�������ݿ������ʧ�ܡ�".mysql_error( ));		
	echo  "���ݿ������: $host    �û����ƣ�$user  <br>";	
		/* ���������õ����������ݿ����Ϣ */
	$database=mysql_list_dbs($conn);				
		/* �����ģ���ӡ���ݿ����Ϣ�� */
	var_dump($database);							
?>
