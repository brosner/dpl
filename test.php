<?php
/**
 * the version of php used to exeucte this code was modified
 * therefore will not run else where
 */


error_reporting(15);

executeLevel;
print "start\n";

$a = 2;

if($a == 8) {
	executeLevel;
	print "a == 8\n";

	$b = 4;

	executeLevel;
	if($b == 5) {
		executeLevel;
		print "b == 5\n";
	}
	else {
		executeLevel;
		print "b != 5\n";
	}
}
else {
	executeLevel;
	print "a != 8\n";
}

executeLevel;

print "end\n";

?>