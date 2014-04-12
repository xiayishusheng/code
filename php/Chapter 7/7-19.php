	<?php									
		$a = array("a"=> "apple",				
				"b"=>"banana");				
		$b=array("a"=>"pear",					
				"b"=>"strawberry",			
				"c"=>"cherry");				
		$c=$a+ $b;							
		echo "Union of \$a and \$b: <br>";		
		var_dump($c);							
		$c = $b + $a;							
	echo  "Union of \$b and \$a:<br>";			
	var_dump($c);								
?>											
