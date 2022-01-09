-- phpMyAdmin SQL Dump
-- version 5.1.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Jan 09, 2022 at 01:57 PM
-- Server version: 10.4.21-MariaDB
-- PHP Version: 8.0.12

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `tempsensoraccesscontrol`
--
CREATE DATABASE IF NOT EXISTS `tempsensoraccesscontrol` DEFAULT CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci;
USE `tempsensoraccesscontrol`;

-- --------------------------------------------------------

--
-- Table structure for table `temperature`
--

CREATE TABLE `temperature` (
  `cardID` varchar(8) NOT NULL,
  `temperature` varchar(5) NOT NULL,
  `time` datetime NOT NULL DEFAULT current_timestamp()
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `temperature`
--

-- --------------------------------------------------------

--
-- Table structure for table `users`
--

CREATE TABLE `users` (
  `cardID` varchar(8) NOT NULL,
  `Name` text NOT NULL,
  `Email` char(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `users`
--

--
-- Indexes for dumped tables
--

--
-- Indexes for table `temperature`
--
ALTER TABLE `temperature`
  ADD UNIQUE KEY `time` (`time`),
  ADD KEY `cardID` (`cardID`);

--
-- Indexes for table `users`
--
ALTER TABLE `users`
  ADD PRIMARY KEY (`cardID`),
  ADD UNIQUE KEY `cardID` (`cardID`),
  ADD UNIQUE KEY `Email` (`Email`);

--
-- Constraints for dumped tables
--

--
-- Constraints for table `temperature`
--
ALTER TABLE `temperature`
  ADD CONSTRAINT `temperature_ibfk_1` FOREIGN KEY (`cardID`) REFERENCES `users` (`cardID`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
