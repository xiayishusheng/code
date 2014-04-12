<?										
	class price{							
	private $price = 88;					
	public function printprice($price){ 	
		echo "现在的价格是  $price 元。";		
		echo "<br>";						
		echo "原来的价格是 $this->price 元。";
		}
	}
	$a = new price();						
	$a->printprice(108);					
?>										
									
