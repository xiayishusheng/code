<?													
	class Math{ 										
		public static function sum($num1,$num2){		
		return $num1 + $num2;							
		}
		public static function product($num1,$num2){
		return $num1 * $num2;							
	}
		}    
	$a = 88;											
	$b = 100;										
	echo "����֮��Ϊ��";								
	echo "<br>";										
	echo Math::sum($a,$b);							
	echo "<P>";										
	$a = 66;											
	$b = 88;											
	echo "����֮��Ϊ��";								
	echo "<br>";										
	echo Math::product($a,$b);							
?>													
											
										
										
