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
	/* �����ģ���ӡ���ݿ����Ϣ */
	/*�õ����ݿ����*/
	$database_count=mysql_num_rows($database);			
		/*�����壺��ʾ���ݿ��ļ���*/
	echo "���������ݿ��ļ����У�<br>";						
	$i=0;											
	while ($i<$database_count) {
		echo mysql_tablename($database,$i)."<br>";		
		$i=$i+1;										
	}
?>

