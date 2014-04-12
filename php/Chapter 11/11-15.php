<?											
	class user{								
	private static $count = 10;				
	private static $sum=1;					
	public function __construct(){ 			
	for($i=1;$i<11;$i++){						
		self::$sum = self::$sum * self::$count
		self::$count--;						
	}			
	}
	public function getCount(){				
		return self::$sum;					
	}
	}
	$user1 = new user();						
	echo "10µÄ½×³ËÎª£º".$user1->getCount();		
?>											
							
										
										
