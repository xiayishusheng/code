<?php
		/* ����һ�����ó�ʼ����*/
	$host="localhost";							
	$user=��root��;									
	$password=��123456��;							
	/* $dbase_name�����ݿ�����*/
	$dbase_name="news"; 
	/* ��������������ݿ������ */
	$conn=mysql_connect($host,$user,$password)  or 	
		die ("�������ݿ������ʧ�ܡ�".mysql_error( ));	
	echo  "���ݿ������: $host    �û����ƣ�$user  <br>";	
		/* ���������õ����ݱ���Ϣ*/
	$tables=mysql_list_tables($dbase_name,$conn);	
		/*�õ����ݱ����Ŀ��*/
	$tables_count=mysql_num_rows($tables);			
		/*�����ģ���ʾ���ݱ��ļ���*/
	echo $dbase_name."���ݿ������ݱ��ļ����У�<br>";	
	$i=0;										
	while ($i<$tables_count) {						
		echo mysql_tablename($tables,$i)."<br>";	
		$i=$i+1;									
}
?>
