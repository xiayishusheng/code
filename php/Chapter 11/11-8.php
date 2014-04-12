<?php										
	class Child{								
	protected $legNum =2;						
	public function getlegNum (){				
		return $this->legNum;					
	}	
	public function speack(){					
		return "It can  speack Chinese.<br>";	
		}
	public function run(){							
		return  "It running¡­.<br>";					
		}
		}
	$ch = new Child();								
	echo "Child have ".$ch-> getlegNum ()."legs.<br>";	
	echo $ch-> speack();								
	echo $ch-> run();									
	class Mychild extends Child{							
													
		private $name="Li L ei";						
		public function getname(){						
			return $this->name;						
			}
		public function speack(){						
			return $this->name.",he is so small that he can speack nothing.";
			}
	}
	$myChild=new Mychild();							
	echo $myChild->getname()." have ".$myChild->getlegNum()." legs";	 	
												
	echo "<br>".$myChild->speack()."<br>";				
	echo $myChild->run();							
?>													

