<?php
	/* ����һ�����ó�ʼ����*/
	$host="localhost";							
	$user="root";									
	$password="123456"; 							
	$db_name="students"; 							
	/* ��������������ݿ������ */
	$conn=mysql_connect($host,$user,$password)  or	
		die ("�������ݿ������ʧ�ܡ�".mysql_error( ));	
	echo  "���ݿ������: $host    �û����ƣ�$user  <br>";	
	/* ���������������ݿ� */
	$mysql_command="create database ".$db_name;		
	$result=mysql_query($mysql_command) or			
   		 die ("�������ݿ�ʧ�ܡ�".mysql_error( ));		
	/* �����ģ������ɹ���ʾ */
	echo "�ɹ��������ݿ�:".$db_name;					
?>
