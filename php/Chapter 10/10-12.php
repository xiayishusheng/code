<?php								
	$dir="D://images";				
	if(is_dir($dir)){					
		$dp=opendir($dir);			
		while($filen=readdir($dp)){	
		print_r($filen."<br>");}		
	}
	else								
	echo "Ä¿Â¼²»´æÔÚ";					
?>									
