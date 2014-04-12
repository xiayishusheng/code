<?php												
	$food = array('fruits' => array('orange',			
							 'banana',				
								'apple'),			
			'veggie' => array('carrot', 'collard','pea'));	
		echo count($food, COUNT_RECURSIVE);			
	echo "<br>";										
	echo count($food);								
?>												