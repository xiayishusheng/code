<?php													
	$string="<b>����: </b><div align=center>21����չ��</div>";	
	preg_match_all ("|<[^>]+>(.*)</[^>]+>|U",				
		$string,											
		$out, PREG_PATTERN_ORDER);							
	print $out[0][0]." ".$out[0][1]."<p>";					
		//print $out[1][0]." ".$out[1][1];
	$patterns= "/21����չ��/";								
	$replacements = "�ع���ʷ";								
	print preg_replace($patterns, $replacements, $string);	
?>														
