<?php
$servername = "localhost";
$username = "id1915238_pogodynka";
$password = "kaczuszka";
$dbname = "id1915238_wstation";

// Create connection
$conn = new mysqli($servername, $username, $password, $dbname);

// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
} 
?>