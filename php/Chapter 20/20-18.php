<?php
		/* ����һ�����ó�ʼ����*/
	$host=��localhost��;								
	$user=��root��;										
	$password=��123456��;								 
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
		/*���ݱ���ֶ�Ϊ����ʱ,���д���ת��.*/
	mysql_query("SET NAMES 'GB2312'"); 				
		/*������:���Ӽ�¼*/
		/*�����������\"���ַ�ת�塣*/
	$mysql_command="insert into ".$table_name."(name,numb,age) values (\"";
													
	$mysql_command=$mysql_command."����\",\"200801\",27)";	
	$result=mysql_query($mysql_command)  or					
		die("���ݱ�:$table_name  ���Ӽ�¼ʧ��!".mysql_error());
	echo "�ɹ��������ݱ�: ".$table_name." �ļ�¼��";			
?>
