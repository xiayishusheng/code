<?php								
	$fp=fopen("foo.txt","r");			
	$fw=fwrite($fp,"hello world");		
	if($fw)							
	echo "д��ɹ�";					
	else								
	echo "ʧ��";						
	fclose($fp);						
?>									
									
