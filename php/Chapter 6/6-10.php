<?php								
	function recurser($n)				
	{
		if($n==0)					
		return 1;					
		else
		return $n* recurser($n-1);		
	}
	$text=recurser(5);				
	echo $text;						
?>									
