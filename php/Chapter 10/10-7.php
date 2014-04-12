<?php										
	$filename='many.txt';						
	$student1="姓名：张三\t年龄:15\t性别：男\r\n";
	$student2="姓名：王二\t年龄:14\t性别：男\r\n";	
	$student3="姓名：李四\t年龄:16\t性别：男\r\n";	
	$student4="姓名：张丽\t年龄:14\t性别：女\r\n";	
		
	If(!$handle=fopen($filename,"w")){			
		print "不能打开文件 $filename ";			
		exit;								
	}
	
	if(!fwrite($handle,$student1)){			
		print "不能写入到文件$filename";			
	exit;									
	}
	print  "成功地将 \" $student1\" 写入到文件$filename<br>";				
											
	fclose($handle);							
		$handle=fopen($filename,"a");			
		//继续添加其他信息
	fwrite($handle,$student2);					
	print "成功地将 \" $student2\" 写入到文件$filename<br>";				
											
	fwrite($handle,$student3);				
	print "成功地将 \" $student3\" 写入到文件$filename<br>";				
										
	fwrite($handle,$student4);				
	print "成功地将 \" $student4\" 写入到文件$filename<br>";				
										
	fclose($handle);						
?>										