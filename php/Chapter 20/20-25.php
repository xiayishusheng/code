<?php
		/* ����һ�����ó�ʼ����*/
	$host=��localhost��;								
	$user=��root��;										
	$password=��123456��;								
	$dbase_name="students"; 							
	$table_name="classone";							
		/* �����������MySQL������ */
	$conn=mysql_connect($host,$user,$password)  or		
		die ("����MySQL������ʧ�ܡ�".mysql_error( ));		
	echo  "MySQL������: $host    �û����ƣ�$user  <br>"; 	
		/* ���������������ݿ� */
	mysql_select_db($dbase_name,$conn) or				
		die ("�������ݿ�ʧ�ܡ�".mysql_error( ));			
	echo  "���ݿ�: $dbase_name    ���ݱ�: $table_name  <br> ";	

	mysql_query("SET NAMES 'GB2312'"); 				
		/*�����ģ��õ����ݼ�¼*/
	$mysql_command="select *  from ".$table_name." where age>20";	
	$result=mysql_query($mysql_command,$conn) or 		
		die ("<br> ���ݱ��޼�¼��<br>");					
		/*�����壺��ʾ����*/
	echo " <br> �������20��ѧ����Ϣ";					
	echo "<table border=1>";
	echo "<tr><td>���</td><td>����</td><td>ѧ��</td><td>����</td></tr>";
	$i=0;										
	while ($record=mysql_fetch_array($result)) {	
	$i=$i+1;
	/* ��ʾ���*/
	echo "<tr><td>$i</td>";						
	/* ��ʾ����*/
	if (strlen($record[name])>0) 					

		echo "<td>$record[name]</td>";				
	else
	echo "<td>&nbsp</td>";						
	/* ��ʾѧ��*/
	if (strlen($record[numb])>0) 					
		echo "<td>$record[numb]</td>";				
	else
		echo "<td>&nbsp</td>";					
	/* ��ʾ����*/
	echo "<td>$record[age]</td></tr>";				
	}
	echo " </table><br>";							
	echo "��¼��:  $i";							
?>
							
