<?php								
	class student 					
	{
		protected $name;				
		protected $score;				
	function __construct(){			
		echo  "I am a student.<br>";	
		}
	}
	class teacher extends student{		
	function __construct()			
	{
		parent::__construct();		
		echo "I am a teacher.<br>" ;	
	}	
	}
	$peo=new teacher();				
?>									
