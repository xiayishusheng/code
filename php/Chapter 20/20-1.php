<?php 
		/* ����һ�����ó�ʼ���� */
	$host="localhost";							
	$user="root";									
	$password="123456";							
		/* �����������MySQL������ */
	$conn=mysql_connect($host,$user,$password);		
	if (!$conn){									
		die ("����MySQL������ʧ�ܡ�".mysql_error( ));	
		}
		/* ����������ʾ���ӽ�� */
	else{										
	echo  "MySQL������:$host <br> �û����ƣ�$user  <br>";	
	echo  "����MySQL�������ɹ���";					
	}
?>

