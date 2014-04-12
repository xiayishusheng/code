<?									
		//使用函数递归实现阶乘功能
	function order($arg)				
	{
		if ($arg>1)					
	return $arg * order($arg -1);		
		return 1;					
	}
	function call()					
		{
		echo " 通过变量调用函数<br> " ;	
	}
	$n=6;							
	$temp = order($n);				
	echo "$n 的阶乘是$temp<br> " ;		
	$arg = "call";					
	$arg( ) ;						
?>									
