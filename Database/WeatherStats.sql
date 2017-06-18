-- phpMyAdmin SQL Dump
-- version 4.6.6
-- https://www.phpmyadmin.net/
--
-- Host: localhost:3306
-- Generation Time: Jun 18, 2017 at 05:24 PM
-- Server version: 10.1.20-MariaDB
-- PHP Version: 7.0.8

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `id1915238_wstation`
--

-- --------------------------------------------------------

--
-- Table structure for table `WeatherStats`
--

CREATE TABLE `WeatherStats` (
  `ID` int(11) NOT NULL,
  `date` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `SID` varchar(20) COLLATE utf8_unicode_ci NOT NULL,
  `temp` varchar(10) COLLATE utf8_unicode_ci NOT NULL,
  `hum` varchar(10) COLLATE utf8_unicode_ci NOT NULL,
  `pres` varchar(10) COLLATE utf8_unicode_ci NOT NULL,
  `wspd` varchar(10) COLLATE utf8_unicode_ci NOT NULL,
  `wdir` varchar(10) COLLATE utf8_unicode_ci NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

--
-- Dumping data for table `WeatherStats`
--

INSERT INTO `WeatherStats` (`ID`, `date`, `SID`, `temp`, `hum`, `pres`, `wspd`, `wdir`) VALUES
(3, '2017-06-15 20:37:21', 'gda1', '14.5', '75', '1005', '3.5', '127'),
(4, '2017-06-15 21:21:13', 'gda1', '14', '70', '1002', '15', '55'),
(5, '2017-06-15 21:21:40', 'gda2', '35', '30', '1015', '30', '0'),
(7, '2017-06-15 22:14:17', 'gda1', '30', '40', '1002', '3', '184'),
(8, '2017-06-16 13:26:25', 'gda3', '38.5', '34', '1004', '4', '25'),
(9, '2017-06-16 13:26:51', 'gda3', '05.5', '15', '1002', '9.5', '127'),
(10, '2017-06-16 13:42:45', 'gda1', '125', '90', '1050', '12', '351'),
(11, '2017-06-16 13:48:31', 'gda2', '34', '35', '1001', '4', '56'),
(12, '2017-06-16 14:51:21', 'gda2', '34', '35', '1001', '4', '56'),
(13, '2017-06-16 14:52:56', 'gda2', '34', '35', '1001', '4', '56'),
(14, '2017-06-16 14:54:27', 'gda2', '24', '41', '1003', '5', '24'),
(15, '2017-06-16 14:54:47', 'gda2', '24', '41', '1003', '5', '24'),
(16, '2017-06-16 14:55:11', 'gda2', '24', '41', '1003', '5', '24');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `WeatherStats`
--
ALTER TABLE `WeatherStats`
  ADD PRIMARY KEY (`ID`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `WeatherStats`
--
ALTER TABLE `WeatherStats`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=17;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
