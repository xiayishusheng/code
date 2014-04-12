<?php											
	class sell{									
		protected $Money =100;					
		protected $price1=60; 					
		public function selled($price){			
			if($this-> price1<=$price){			
			echo "好，$price 元卖给你了。<br>";		
			$this->Money = $this->Money+$price;	
			}
	else{										
				echo "我不卖 ,$price 太便宜了<br>";
			}
		}
	}
			//继承后的类可以方法父类的protected属性。
		class now extends sell {					
			public function getMoney(){			
			return $this->Money;					
			}
		}
		$Me = new now ();							
		$Me->selled(110);							
	echo "现在我的钱数是:<br>".$Me->getMoney();		
?>												
