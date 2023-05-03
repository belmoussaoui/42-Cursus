<?php

parse_str($_SERVER['QUERY_STRING'], $_GET);

echo "<h1>Substraction Results</h1>";

$num1 = $_GET['num1'];
$num2 = $_GET['num2'];

$sub = $num1 - $num2;

echo "<output>$num1 - $num2 = $sub</output>";
?>