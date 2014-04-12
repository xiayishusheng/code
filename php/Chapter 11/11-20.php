<?php								
	class  Text{						
		function   print_Text($x)		
		{
			for($i=1; $i<=$x;$i++){	
			for($j=1;$j<=$i;$j++){	
			echo $j."x".$i."=";		
			echo $i*$j."&nbsp";		
	}
	echo  "<br>";						
		}
	}
	}
		$Textl=new Text;				
		$Textl->print_Text(9);		
		echo  "<br>";					
		$Text2=new Text;				
		$Text2->print_Text(6);		
		echo  "<br>";					
		$Text3=new Text;				
		$Text3->print_Text(3);		
?>									
