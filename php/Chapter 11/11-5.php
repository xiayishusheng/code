<?php												
	class me{										
	protected $Money =100;							
	protected $price1=60;								
													
	public function Sell($price){						
		if($this->price1<=$price){						
			echo "�ã��������ˡ�<br>";					
			$this->Money = $this->Money+$price;		
			return "�������ܹ��� ".$this->Money." ԪǮ";	
		}
	else{											
		echo "�Ҳ��� ,$price ̫������<br>";				
		return "�����һ��� ".$this->Money." ԪǮ";		
			}
		}
	}

	$now=new me;										
	echo $now->Sell(30); 								
?>													
												