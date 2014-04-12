<?php								
	$fp=fopen("foo.txt","r");			
	$fw=fwrite($fp,"hello world");		
	if($fw)							
	echo "Ð´Èë³É¹¦";					
	else								
	echo "Ê§°Ü";						
	fclose($fp);						
?>									
									
