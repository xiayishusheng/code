<?php										
	$filename='many.txt';						
	$student1="����������\t����:15\t�Ա���\r\n";
	$student2="����������\t����:14\t�Ա���\r\n";	
	$student3="����������\t����:16\t�Ա���\r\n";	
	$student4="����������\t����:14\t�Ա�Ů\r\n";	
		
	If(!$handle=fopen($filename,"w")){			
		print "���ܴ��ļ� $filename ";			
		exit;								
	}
	
	if(!fwrite($handle,$student1)){			
		print "����д�뵽�ļ�$filename";			
	exit;									
	}
	print  "�ɹ��ؽ� \" $student1\" д�뵽�ļ�$filename<br>";				
											
	fclose($handle);							
		$handle=fopen($filename,"a");			
		//�������������Ϣ
	fwrite($handle,$student2);					
	print "�ɹ��ؽ� \" $student2\" д�뵽�ļ�$filename<br>";				
											
	fwrite($handle,$student3);				
	print "�ɹ��ؽ� \" $student3\" д�뵽�ļ�$filename<br>";				
										
	fwrite($handle,$student4);				
	print "�ɹ��ؽ� \" $student4\" д�뵽�ļ�$filename<br>";				
										
	fclose($handle);						
?>										