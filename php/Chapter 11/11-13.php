<?										
	class price{							
	private $price = 88;					
	public function printprice($price){ 	
		echo "���ڵļ۸���  $price Ԫ��";		
		echo "<br>";						
		echo "ԭ���ļ۸��� $this->price Ԫ��";
		}
	}
	$a = new price();						
	$a->printprice(108);					
?>										
									
