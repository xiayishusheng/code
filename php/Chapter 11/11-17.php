<?php											
	class circle{									
	public $radius=10;							
	const pi=3.14159;								
	final function area(){						
		echo "�뾶=",$this->radius;				
		echo "<br>���=";							
		echo self:: pi*$this->radius*$this->radius;	
		}
		}
												
	$cir=new circle();							
	$cir->area();									
?>												
