<?php 
	/* ����һ�����ó�ʼ���� */
	$host="127.0.0.1";									
	$user="root";										
	$password="cntrust";								
	/* �����������MySQL������ */
	$conn=mysql_connect($host,$user,$password);			
	//���������ж����ӽ��
	if (!$conn){
		die ("�������ݿ�ʧ�� ".mysql_error());		
	}
	else{
		echo  "MySQL������: $host <br> �û����ƣ�$user  <br>"; 
		echo  "�ɹ��������ݿ⡣";						
	}
?>
