<?php											
	class circle{									
	public $radius=10;							
	const pi=3.14159;								
	final function area(){						
		echo "°ë¾¶=",$this->radius;				
		echo "<br>Ãæ»ý=";							
		echo self:: pi*$this->radius*$this->radius;	
		}
		}
												
	$cir=new circle();							
	$cir->area();									
?>												
