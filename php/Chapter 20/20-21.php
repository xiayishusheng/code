<?php
		/* ����һ�����ó�ʼ����*/
	$host=��localhost��;								
	$user=��root��;										
	$password=��123456��;								
		/* $dbase_name�����ݿ�����  $table_name���ݱ�����*/
	$dbase_name="people"; $table_name="students";		
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
		/*�����ģ��õ����ݼ�¼����*/
	$mysql_command="select * from  ".$table_name;		
	$result=mysql_query($mysql_command,$conn) or 		
		die ("<br> ���ݱ��޼�¼��<br>");					
		/*�����壺������ʾ��¼*/
	$i=0;
	while ( $record=mysql_fetch_row($result)) {			
		$i=$i+1;
		echo " I D��: ".$record[0];					
		echo " ����: ".$record[1]; 						
		echo " ����: ".$record[2]; 						
		 echo " �Ա�: ".$record[3]; 					
		echo " �绰: ".$record[4]; 						
		echo "<br>";									
	}   
	echo "�ɹ���ʾ���ݱ�: ".$table_name." �ļ�¼����¼��:";echo  $i;	
?>
