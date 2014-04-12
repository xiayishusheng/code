<?php 										
	if (empty($_POST['college']))				
	echo "您没有选择学校名称。";					
	if (empty($_POST['student']))				
	echo  "您没有输入姓名。". "<br>";				
	if ($_POST['numb']<0)						
	echo "您没有输入学号。". "<br>";				
		//输入的学号
	if (!is_numeric($_POST['numb']))			
	die ("学号应为数字。". "<br>");				
	echo "<br>你的学校是:".$_POST['college']. "<br>";		
	echo "您的名字是：".$_POST['student']. "<br>"; 		
	echo "您的学号是：".$_POST['numb']. "<br>"; 			
?>												
