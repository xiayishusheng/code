<?php 
	/* ����һ�����ó�ʼ���� */
	$host="localhost";							
	$user="root";									
	$password="123456";							
		/* �����������MySQL������ */
	$conn=mysql_pconnect($host,$user,$password); 	
	if (!$conn){									
		die ("����MySQL������ʧ�ܡ�".mysql_error( ));
		}
	else{										
	echo  "MySQL������:$host<br>�û����ƣ�$user  <br>";	
	echo  "ʹ��mysql_pconnect()�����������ݿ�";		
	}
?>
