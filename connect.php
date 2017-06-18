<?php
/**@file
 * @brief Connects weather station with database
 *
 *	Script connecting weather station with database. Database can be local or remote.
 *	

 *	@version 1.0
 *	@date 06/2017
 *
 *	
 *
 */

$servername = "localhost"; /*!< Server's address*/
$username = "username"; /*!<Username*/
$password = "passoword"; /*!<User's password*/
$dbname = "databasename"; /*!<Database's name*/


$conn = new mysqli($servername, $username, $password, $dbname); /*!<Handler of connection */


if ($conn->connect_error) { // Checking the connection
    die("Connection failed: " . $conn->connect_error);
} 
echo "Connected successfully";
?>