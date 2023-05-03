<?php
$value = 1;
if (isset($_SERVER['HTTP_COOKIE'])) {
  $cookies = explode(';', $_SERVER['HTTP_COOKIE']);
  foreach($cookies as $cookie) {
      $parts = explode('=', $cookie);
      $name = trim($parts[0]);
      if ($name == 'click') {
          $value = isset($parts[1]) ? trim($parts[1]) : $value;
          $value = intval($value) + 1;
      }
  }
}

$expiration_time = time() + (60 * 60);
$cookie_string = "Set-Cookie: "."click={$value}; expires=".$expiration_time.";\r\n";
echo "Content-Type: text/html\r\n";
echo $cookie_string;
echo "\r\n";
?>
<html>
<head>
<title>Exemple de cookie en PHP</title>
</head>
<body>
<h1>Number of times you have visited the page</h1>
<span>
<?php
  echo "La valeur du cookie est " . $value . "!<br>";
  unset($_SERVER['HTTP_COOKIE']);
?>
</span>
</body>
</html>