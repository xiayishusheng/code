<?								
		//使用mkdir()函数创建目录
	$dirname="pic";  				
	$str=mkdir($dirname,100); 		
	if($str)						
	echo "创建成功";				
	else							
	echo "创建失败" ;				
?>								
