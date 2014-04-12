<?php											
	$str = 'PHP is a Web language';				
	$chars = preg_split('/ /', $str, -1, PREG_SPLIT_OFFSET_CAPTURE);	
												
	echo "<h2> 被分隔成单词了：</h2>";				
	print_r($chars);								
?>												
