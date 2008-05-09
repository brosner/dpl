<?php

function getmicrotime() { 
   list($usec, $sec) = explode(" ", microtime()); 
   return ((float)$usec + (float)$sec); 
}

$size = 999999;
$range = range(0,$size);

$start = time();
for($i = 0; $i < $size; $i++) {
	$index = rand(0,$size);
	$new[] = $range[$index];
}
$end = time();

for($i = 0; $i < 100; $i++) {
	printf("%d ",$new[$i]);
}

printf("\n\nTook %d seconds to randomize\n",$end - $start);

?>