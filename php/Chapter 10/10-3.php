<?									
	$filename=fopen("text.txt","r");
	$char=fgetc($filename);			
	echo $char;						
	fclose($filename);				
?>									
