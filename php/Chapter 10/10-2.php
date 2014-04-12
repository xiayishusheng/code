<?														
	$filename="text.txt";									
	echo $filename."的大小为: ".filesize($filename)."<br>";	
	echo $filename."的类型为: ".filetype($filename)."<br>";	
	echo $filename."的修改时间为:".date("Y 年 n 月 t 日",fileatime($filen ame))."<br>";							
	echo $filename."访问时间为:".date("Y 年 n 月 t 日", fileatime($filen ame))."<br>";							
	echo $filename."的权限为 :".fileperms($filename)."<br>";	
?>														
