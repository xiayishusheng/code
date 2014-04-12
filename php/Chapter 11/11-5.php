<?php												
	class me{										
	protected $Money =100;							
	protected $price1=60;								
													
	public function Sell($price){						
		if($this->price1<=$price){						
			echo "好，卖给你了。<br>";					
			$this->Money = $this->Money+$price;		
			return "我现在总共有 ".$this->Money." 元钱";	
		}
	else{											
		echo "我不卖 ,$price 太便宜了<br>";				
		return "现在我还是 ".$this->Money." 元钱";		
			}
		}
	}

	$now=new me;										
	echo $now->Sell(30); 								
?>													
												