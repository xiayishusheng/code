<?										
										
	final class Math{						
	public static $pi = 3.14;				
	public function area($radius){  		
		return self:: pi*$radius*$radius;	
		}
		}
	//ÉùÃ÷circle ¼Ì³Ð×ÔMathÀà.
	class circle extends Math{				
		function area($r){				
			return 2*3.14 * $r;			
		}
	}
	$cir=new circle();					
	echo $cir->area(3);					
?>										
								
