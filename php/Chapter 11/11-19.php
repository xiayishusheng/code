<?									
									
	class Math{  						
		const pi=3.14159;				
		public function string(){		
		return "����Math��.";			
		}
		final function sum($a,$b){		
			return $a + $b;			
		}
	}
	//����SuperMath �̳���Math��.
	class SuperMath extends Math{		
		public  function sum($a,$b){;	
		return $a * $b;				
		}
	}
	$cir=new SuperMath();				
	echo $cir->sum(4,5)				
?>									
