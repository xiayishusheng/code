<?														
	$filename="text.txt";									
	echo $filename."�Ĵ�СΪ: ".filesize($filename)."<br>";	
	echo $filename."������Ϊ: ".filetype($filename)."<br>";	
	echo $filename."���޸�ʱ��Ϊ:".date("Y �� n �� t ��",fileatime($filen ame))."<br>";							
	echo $filename."����ʱ��Ϊ:".date("Y �� n �� t ��", fileatime($filen ame))."<br>";							
	echo $filename."��Ȩ��Ϊ :".fileperms($filename)."<br>";	
?>														
