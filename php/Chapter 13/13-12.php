<?php													
	$string="<b>标题: </b><div align=center>21世纪展望</div>";	
	preg_match_all ("|<[^>]+>(.*)</[^>]+>|U",				
		$string,											
		$out, PREG_PATTERN_ORDER);							
	print $out[0][0]." ".$out[0][1]."<p>";					
		//print $out[1][0]." ".$out[1][1];
	$patterns= "/21世纪展望/";								
	$replacements = "回顾历史";								
	print preg_replace($patterns, $replacements, $string);	
?>														
