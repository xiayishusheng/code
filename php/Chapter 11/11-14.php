<?												
	class comp{									
		public function sum($a,$b){				
		return $a+$b;								
	}				
		public function prt($a,$c){				
		return $a*$c;								
	}				
	public function product($a,$b,$c){				
	$a = $this->sum($a,$b);						
	return $this->prt($a,$c);						
		}				
	}
	$math = new comp();							
	echo "(5+10)*15�Ľ��Ϊ".$math->product(5,10,15);
?>												
									
