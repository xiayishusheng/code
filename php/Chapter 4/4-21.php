<?php 										
  $a=5;										
  $b=$a;										
  $c=&$a;										
  echo "��ʼֵ��<br>";							
  echo "\$a=$a <br> \$b=$b <br> \$c=$c <p>";	
  $b++;										
  echo "$b�Ӻ�<br>";							
  echo "\$a=$a <br> \$b=$b <br> \$c=$c <p>";	
  $a++;										
  $a++;										
  echo "$a�Ӻ�<br>";							
  echo "\$a=$a <br> \$b=$b <br> \$c=$c ";		
?>											
