<?php												
	function areas($weight,$length){					
		function convert_pound($heigh, $price=2.1){		
			return $heigh*$price;						
	}
		$area=$weight*$length;						
		echo " Total cost in ". convert_pound($area);	
		}
	areas(2,3.6);										
?>													
