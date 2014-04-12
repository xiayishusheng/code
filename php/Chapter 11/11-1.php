<?php							
	class Student{				
	var $name;					
	function setName($name){		
		$this->name=$name;		
	}
	function getName(){			
		return $this->name;		
		}
	}
								
	$n=new Student ( );			
	$n->setname("Li Lei");		
	echo $n->getname();			
?>								
