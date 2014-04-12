<?php											
	$count=$_COOKIE[nam];							
	$count++;									
	setcookie("nam",$count,time()+300);			
	echo "欢迎光临！<br>你是第 $count 位光临本站者";		
?>												
