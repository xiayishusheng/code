<?php 										
  $a=5;										
  $b=$a;										
  $c=&$a;										
  echo "初始值：<br>";							
  echo "\$a=$a <br> \$b=$b <br> \$c=$c <p>";	
  $b++;										
  echo "$b加后：<br>";							
  echo "\$a=$a <br> \$b=$b <br> \$c=$c <p>";	
  $a++;										
  $a++;										
  echo "$a加后：<br>";							
  echo "\$a=$a <br> \$b=$b <br> \$c=$c ";		
?>											
