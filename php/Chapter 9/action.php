<?php 										
	if (empty($_POST['college']))				
	echo "��û��ѡ��ѧУ���ơ�";					
	if (empty($_POST['student']))				
	echo  "��û������������". "<br>";				
	if ($_POST['numb']<0)						
	echo "��û������ѧ�š�". "<br>";				
		//�����ѧ��
	if (!is_numeric($_POST['numb']))			
	die ("ѧ��ӦΪ���֡�". "<br>");				
	echo "<br>���ѧУ��:".$_POST['college']. "<br>";		
	echo "���������ǣ�".$_POST['student']. "<br>"; 		
	echo "����ѧ���ǣ�".$_POST['numb']. "<br>"; 			
?>												
