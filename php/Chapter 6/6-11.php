<?php									
	function testvar()  {					
		echo "testvar()����<br>";			
	}
		function setname($string){			
		echo "my name is $string" ;		
	}
	$rtext= 'testvar';					
	$rtext();							
	$rtext='setname';						
	$rtext("Jun");						
?>										
