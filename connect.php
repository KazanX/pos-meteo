<?php
$servername = "localhost"; // Adres serwera z baza danych
$username = "username"; // Nazwa uzytkownika
$password = "passoword"; // Haslo
$dbname = "databasename"; // nazwa bazy danych


$conn = new mysqli($servername, $username, $password, $dbname); // Stworzenie polaczenia


if ($conn->connect_error) { // Sprawdzenie poprawnosci utworzonego polaczenia
    die("Connection failed: " . $conn->connect_error);
} 
echo "Connected successfully";
?>