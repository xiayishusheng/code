<?php								
	$fp=fopen("many.txt","r");			
	//���ǰ15���ַ�
	$data=fgets($fp,15);				
	//��ȡ��ǰָ��
	echo ftell($fp);					
	fclose($fp);						
?>									
