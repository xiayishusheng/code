<?php
		/* ����һ�����ó�ʼ����*/
	$host="localhost��;								
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
		/*�����ģ��õ����ݼ�¼*/
	$mysql_command="select * from ".$table_name." where age>20  ";
													
	$result=mysql_query($mysql_command,$conn) or 		
	die ("<br> ���ݱ��޼�¼��<br>");						
		/*�����壺��ʾ����*/
	$record_count =mysql_num_rows($result);
	echo " <br> ѧ����Ϣ�� ";							
	echo "<table border=1>";							
	echo "<tr><td>�������20�ļ�¼��</td></tr>";			
	echo "<tr><td>$record_count </td></tr>";			
	echo " </table>";									
?>

