<?php							
	$dir="D://images";			
	if(is_dir($dir)){				
		$dp=opendir($dir);		
		print_r("目录已被打开");	
	}
	else							
	echo "目录不存在";				
?>								

