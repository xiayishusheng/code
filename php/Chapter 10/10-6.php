<?php										
	$filename='onlyone.txt’;					
	$wr="我先被写入的！";						
	$wr1="我后被写入的！";						
		
	if(is_writable($filename))					
		{		
		
		if(!$handle=fopen ($filename,"w")){	
			print "不能打开文件 $filename ";		
			exit;							
		}
			//将$wr写入到打开的文件中
		if(!fwrite($handle,$wr)){				
			print "不能写入到文件 $filename";	
			exit;							
		}
		print "成功地将 \"$wr\" 写入到文件$filename<br>";					
											
		fclose($handle);						
		$handle=fopen($filename,"w");			
		fwrite($handle,$wr1);					
		fclose($handle);						
		print "成功地将 \"$wr1\" 写入到文件$filename";						
											
	} 
	else{									
		print "文件 $filename 不可写";			
	}
?>											
