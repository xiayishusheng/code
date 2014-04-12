<?									
	//循环读取文件所有内容
	$filename=fopen("text.txt","r");	
	do
	{
		$mychar=fgetc($filename);		
		echo $mychar;					
		}while(!feof($filename)) ; 	
	fclose($filename);				
?>									
