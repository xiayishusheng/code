<?								
	$myfile=fopen("text.txt","r");	
	$file=fgets($myfile,1024);		
	echo $file;					
	fclose($myfile); 				
?>								
