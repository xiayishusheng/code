<?php								
	echo "<center> 获奖名单</center> ";	
	$string="王晓华  刘晓莉  张坤三";		
	if(ereg ("刘晓莉", $string)){		
		echo "有我<br>";				
	}
	if(ereg ("^刘晓莉", $string)){		
	echo "刘晓莉是第一个<br>";			
	}
	if(ereg ("^王晓华", $string)){		
	echo "王晓华是第一个<br>";			
	}
?>									
