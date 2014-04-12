<?php											
	$int1=1;										
	$int2=2;										
	function fun1(){								
		$GLOBALS["int1"]= $GLOBALS["int1"]+$GLOBALS["int2"];
												
	}
	fun1();										
	echo $int1									
?>												
