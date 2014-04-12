<?										
	$Cities[] = "<B>北京</B>";				
	$Cities[] = "<B>天津</B>";				
	$Cities[] = "<B>上海</B>";				
	$Cities[] = "<B>深圳</B>";				
	/* 
	** 统计元素个数 
	*/
	$indexLimit = count($Cities);			
	/* 
	** 打印所有数组 
	*/
	for($index=0; $index < $indexLimit; $index++)			
	{
		print("第 $index 个城市是 $Cities[$index]。 <BR>");	
	}
?>														
