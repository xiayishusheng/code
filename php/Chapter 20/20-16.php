<?php
		/* ����һ�����ó�ʼ����*/
	$host="localhost";								
	$user=��root��;										
	$password=��123456��;								
	/* $db_name�����ݿ�����  $table_name���ݱ�����*/
	$db_name="students"; 								
	$table_name="classone";							
		/* �����������MySQL������ */
	$conn=mysql_connect($host,$user,$password)  or		
		die ("����MySQL������ʧ�ܡ�".mysql_error());		
	echo  "���ݿ������: $host    �û����ƣ�$user  <br>";		
		/* ���������������ݿ� */
	mysql_select_db($db_name,$conn) or					
		die ("�������ݿ�ʧ�ܡ�".mysql_error());			
	echo  "���ݿ�: $db_name    ���ݱ�: $table_name  <br> ";	
													
		/* �����ģ���ʾ���ݱ���ֶ���Ϣ */
		/*���ݱ���ֶ�Ϊ����ʱ,���д���ת��.*/
	mysql_query("SET NAMES 'GB2312'"); 				
		/*�õ����ݱ���ֶ���Ϣ��*/
	$fields=mysql_list_fields($db_name,$table_name,$conn);	
		/*�õ����ݱ���ֶθ�����*/
	$field_count=mysql_num_fields($fields);				
	echo $table_name."���ݱ���ֶθ�����";				
	echo $field_count;								
?>


