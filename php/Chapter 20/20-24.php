<?php
		/* ����һ�����ó�ʼ����*/
	$host="localhost";								
	$user=��root��;										
	$password=��123456��;								
	/* $db_name�����ݿ�����  $table_name���ݱ�����*/
	$db_name="study"; 								
	$table_name="books";								
	/* �����������MySQL������ */
	$conn=mysql_connect($host,$user,$password)  or		
		die ("����MySQL������ʧ�ܡ�".mysql_error( ));		
	echo  "MySQL������: $host    �û����ƣ�$user  <br>"; 	
	/* ��������������ݿ� */
	$mysql_command="drop  database  if  exists ".$db_name;	
	$result=mysql_query($mysql_command);				
	/* �����ģ��������ݿ� */
	$mysql_command="create database ".$db_name;			

	$result=mysql_query($mysql_command) or				
		die ("�������ݿ�ʧ�ܡ�".mysql_error( ));			
	mysql_select_db($db_name,$conn) or					
		die ("�������ݿ�ʧ�ܡ�".mysql_error( ));			
	echo  "���ݿ�: $db_name    ���ݱ�: $table_name  <br> ";	

		/*���д���ת��.*/
	mysql_query("SET NAMES 'GB2312'"); 				
		/*�����壺�������ݱ�*/ 
	$mysql_command="create table ".$table_name;			
	$mysql_command=$mysql_command."(���� varchar(30),�۸� varchar(10),������varchar(100))";
	$result=mysql_query($mysql_command)  or				
		die ("�������ݱ�:$table_nameʧ��!".mysql_error( ));
	echo "�ɹ��������ݱ��ļ���$table_name";				
?>

