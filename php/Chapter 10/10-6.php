<?php										
	$filename='onlyone.txt��;					
	$wr="���ȱ�д��ģ�";						
	$wr1="�Һ�д��ģ�";						
		
	if(is_writable($filename))					
		{		
		
		if(!$handle=fopen ($filename,"w")){	
			print "���ܴ��ļ� $filename ";		
			exit;							
		}
			//��$wrд�뵽�򿪵��ļ���
		if(!fwrite($handle,$wr)){				
			print "����д�뵽�ļ� $filename";	
			exit;							
		}
		print "�ɹ��ؽ� \"$wr\" д�뵽�ļ�$filename<br>";					
											
		fclose($handle);						
		$handle=fopen($filename,"w");			
		fwrite($handle,$wr1);					
		fclose($handle);						
		print "�ɹ��ؽ� \"$wr1\" д�뵽�ļ�$filename";						
											
	} 
	else{									
		print "�ļ� $filename ����д";			
	}
?>											
