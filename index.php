<?php
include('dbconnect.php'); //Zestawienie polaczenia z baza danych
if(isset($_POST['ws'])){ //Sprawdzenie czy zostal przeslany parametr za pomoca metody POST
$stationID = $_POST['ws']; //Wybranie stacji pogodowej
}
else{
$stationID = "gda1";
}
?>

<html>
<head>
<meta charset="UTF-8" />
<title>POGODA DLA TWOJEJ OKOLICY</title>
</head>
<body>
<body bgcolor=ADFF2F />

<nav>
<a href="main.htm">Strona g³ówna</a>
</nav>

<header>
<center><img src="photos\logo_small.png" alt="LOGO TEWC"/></center>
<br/>
WYBIERZ STACJE Z TWOJEJ OKOLICY
</header>




<form action="index.php" method="post">
<select name="ws">
<option value="gda1">Gdañsk 001</option>
<option value="gda2">Gdañsk 002</option>
<option value="gda3">Gdañsk 003</option>
<select>
<input type="submit" value="Wybierz">
</form>



<section>
<article>
<center>Aktualna pogoda (na dzieñ 
<?php
$requestdate = current($conn -> query("SELECT date FROM ".$dbname.".WeatherStats WHERE SID='".$stationID."' ORDER BY id DESC LIMIT 1")->fetch_assoc());
echo $requestdate
?>
): 
				
				
						
<br />
<table>
<tr><td>IDENTYFIKATOR:</td>	<td>
<?php 
echo $stationID 
?></td></tr>
<tr><td>TEMPERATURA:</td><td>
<?php
$request = current($conn -> query("SELECT temp FROM ".$dbname.".WeatherStats WHERE SID='".$stationID."' ORDER BY id DESC LIMIT 1")->fetch_assoc());
echo $request
?> &#186C</td></tr>

<tr><td>CIŒNIENIE:</td><td>
<?php
$request = current($conn -> query("SELECT pres FROM ".$dbname.".WeatherStats WHERE SID='".$stationID."' ORDER BY id DESC LIMIT 1")->fetch_assoc());
echo $request
?> hPa</td></tr>

<tr><td>PRÊDKOŒÆ WIATRU:</td><td>
<?php
$request = current($conn -> query("SELECT wspd FROM ".$dbname.".WeatherStats WHERE SID='".$stationID."' ORDER BY id DESC LIMIT 1")->fetch_assoc());
echo $request
?> m/s</td></tr>

<tr><td>KIERUNEK WIATRU:</td><td>
<?php
$request = current($conn -> query("SELECT wdir FROM ".$dbname.".WeatherStats WHERE SID='".$stationID."' ORDER BY id DESC LIMIT 1")->fetch_assoc());
echo $request
?>&#186</td></tr>

<tr><td>WILGOTNOŒÆ:</td><td>
<?php
$request = current($conn -> query("SELECT hum FROM ".$dbname.".WeatherStats WHERE SID='".$stationID."' ORDER BY id DESC LIMIT 1")->fetch_assoc());
echo $request
?>%</td></tr>

</table>
</center>
</article>
</section>

<aside>
<a target="_blank" href="http://eti.pg.edu.pl/">Strona naszego sposonsora</a>
</aside>
<footer>
<br />
<hr width="80%" />
<br />
<br />
<center>STRONA JEST CZEŒCI¥ PROJEKTU z POS 
<br/> <br/>
Sylwia Biliñska, Anna Strahl, Adrian Kazanowski, Jakub Roziewski, maj 2017</center>
 </footer>
</body>
</html>