<?									
		//ʹ�ú����ݹ�ʵ�ֽ׳˹���
	function order($arg)				
	{
		if ($arg>1)					
	return $arg * order($arg -1);		
		return 1;					
	}
	function call()					
		{
		echo " ͨ���������ú���<br> " ;	
	}
	$n=6;							
	$temp = order($n);				
	echo "$n �Ľ׳���$temp<br> " ;		
	$arg = "call";					
	$arg( ) ;						
?>									
