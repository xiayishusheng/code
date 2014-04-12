<?									
									
	class Math{  						
		const pi=3.14159;				
		public function string(){		
		return "这是Math类.";			
		}
		final function sum($a,$b){		
			return $a + $b;			
		}
	}
	//声明SuperMath 继承自Math类.
	class SuperMath extends Math{		
		public  function sum($a,$b){;	
		return $a * $b;				
		}
	}
	$cir=new SuperMath();				
	echo $cir->sum(4,5)				
?>									
