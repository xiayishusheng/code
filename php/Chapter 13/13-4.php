<?php									
	echo "<center> 获奖名单</center> ";		
	$string="王晓华  刘晓莉  张坤三";			
	if(ereg ("王晓华$", $string)){			
		echo "王晓华是最后一个<br>";			
	}
	else									
	if(ereg ("张坤三$", $string)){			
		echo "张坤三是最后一个<br>";			
	}
	else echo "刘晓莉是最后一个"				
?>										

