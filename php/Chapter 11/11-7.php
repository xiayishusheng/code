<?php											
	class sell{									
		protected $Money =100;					
		protected $price1=60; 					
		public function selled($price){			
			if($this-> price1<=$price){			
			echo "�ã�$price Ԫ�������ˡ�<br>";		
			$this->Money = $this->Money+$price;	
			}
	else{										
				echo "�Ҳ��� ,$price ̫������<br>";
			}
		}
	}
			//�̳к������Է��������protected���ԡ�
		class now extends sell {					
			public function getMoney(){			
			return $this->Money;					
			}
		}
		$Me = new now ();							
		$Me->selled(110);							
	echo "�����ҵ�Ǯ����:<br>".$Me->getMoney();		
?>												
