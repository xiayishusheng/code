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

		/*���ݱ���ֶ�Ϊ����ʱ,���д���ת��.*/
	mysql_query("SET NAMES 'GB2312'"); 				
		/*�����ģ��õ����ݼ�¼*/
	$mysql_command="select * from ".$table_name;		
	$result=mysql_query($mysql_command,$conn) or 		
		die ("<br> ���ݱ��޼�¼��<br>");					
	$record=mysql_data_seek($result,1);				
	$rec=mysql_fetch_array($result);					

	/*�����壺��ʾ����*/
	echo " <br> ѧ��������Ϣ ";							
	echo "<table border=1>";							
	echo "<tr><td>�� ��</td><td>�� ��</td></tr>";			
	echo "<tr>";										
	echo "    <td>$rec[name]</td>";						
	echo "    <td> $rec[age]</td></tr>";				
	echo " </table>"; 								
?>
