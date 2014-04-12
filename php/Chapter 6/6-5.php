<?php										
	function salestax ($amount, $rate=0.0725)	
	{
		echo "<br>amount=$amount";				
		echo "<br>rate=$rate";				
		return $amount*$rate;					
	}
	$purchase=123.45;							
	echo "<br>purchase=$purchase";				
	$tax=salestax($purchase,0.08);				
	echo "<br>tax=$tax";						
	$purchase=123.45;							
	echo "<br>purchase=$purchase";				
	$tax=salestax($purchase);					
	echo "<br>tax=$tax";						
?>											
