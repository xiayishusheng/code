<?php
		/* ����һ�����ó�ʼ����*/
	$host="localhost";								
	$user="root";										
	$password="123456";								
		/* $dbase_name�����ݿ�����  $table_name���ݱ�����*/
	$dbase_name="students"; 							
	$table_name="classone";							
		/* ��������������ݿ������ */
	$conn=mysql_connect($host,$user,$password)  or			
		die ("�������ݿ������ʧ�ܡ�".mysql_error());			
	echo  "���ݿ������: $host    �û����ƣ�$user  <br>";
		/* ���������������ݿ� */
	mysql_select_db($dbase_name,$conn) or					
		die ("�������ݿ�ʧ�ܡ�".mysql_error());				
	echo  "���ݿ�: $dbase_name    ���ݱ�: $table_name  <br> ";	
														
		/*���д���ת��.*/
	mysql_query("SET NAMES 'GB2312'"); 					
		/*�����ģ��޸ļ�¼*/
	$mysql_command="update ".$table_name." set name=\"����\"";
		$mysql_command=$mysql_command."  where  name=\"����\"";
	$result=mysql_query($mysql_command)  or					
		die ("���ݱ�:$table_name  �޸ļ�¼ʧ��!".mysql_error());
	echo "�ɹ��޸����ݱ�: ".$table_name." �ļ�¼��";			
?>
