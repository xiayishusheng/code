<?									
	//ѭ����ȡ�ļ���������
	$filename=fopen("text.txt","r");	
	do
	{
		$mychar=fgetc($filename);		
		echo $mychar;					
		}while(!feof($filename)) ; 	
	fclose($filename);				
?>									
