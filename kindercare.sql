-- phpMyAdmin SQL Dump
-- version 5.1.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Feb 17, 2022 at 05:50 PM
-- Server version: 10.4.22-MariaDB
-- PHP Version: 8.0.15

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `kindercare`
--

-- --------------------------------------------------------

--
-- Table structure for table `assignments`
--

CREATE TABLE `assignments` (
  `assignment_id` varchar(20) NOT NULL,
  `characters` mediumtext CHARACTER SET utf8mb4 COLLATE utf8mb4_bin NOT NULL,
  `expiry_date` date NOT NULL,
  `attempt_status` mediumtext NOT NULL DEFAULT 'not_attempted',
  `activation_status` mediumtext NOT NULL DEFAULT 'activated',
  `release_` tinytext NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `assignments`
--

INSERT INTO `assignments` (`assignment_id`, `characters`, `expiry_date`, `attempt_status`, `activation_status`, `release_`) VALUES
('a000', 'FQXSY', '2022-02-25', 'not_attempted', 'activated', 'on'),
('a001', 'NOKR', '2022-02-26', 'not_attempted', 'deactivated', 'on'),
('a003', 'LL', '2022-02-20', 'attempted', 'activated', 'on'),
('a004', 'WXYZ', '2022-02-02', 'missed', 'activated', 'on'),
('a005', 'UVD', '2022-02-10', 'attempted', 'activated', 'on');

-- --------------------------------------------------------

--
-- Table structure for table `attempt`
--

CREATE TABLE `attempt` (
  `attempt_id` int(11) NOT NULL,
  `pupil_code` varchar(20) NOT NULL,
  `assignment_id` varchar(20) NOT NULL,
  `average_score` float DEFAULT NULL,
  `attempt_duration_in_seconds` float DEFAULT NULL,
  `teacher_comment` mediumtext DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `attempt`
--

INSERT INTO `attempt` (`attempt_id`, `pupil_code`, `assignment_id`, `average_score`, `attempt_duration_in_seconds`, `teacher_comment`) VALUES
(15, 'p000', 'a003', 92.86, 77.78, 'Keep it up');

-- --------------------------------------------------------

--
-- Table structure for table `pupils`
--

CREATE TABLE `pupils` (
  `pupil_code` varchar(8) NOT NULL,
  `pupil_name` varchar(20) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `pupils`
--

INSERT INTO `pupils` (`pupil_code`, `pupil_name`) VALUES
('p000', 'sempiira'),
('p001', 'sibo');

-- --------------------------------------------------------

--
-- Table structure for table `requests`
--

CREATE TABLE `requests` (
  `request_id` int(11) NOT NULL,
  `pupil_code` varchar(20) NOT NULL,
  `assignment_id` varchar(20) NOT NULL,
  `message` longtext NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `requests`
--

INSERT INTO `requests` (`request_id`, `pupil_code`, `assignment_id`, `message`) VALUES
(27, 'p000', 'a003', 'I was sick'),
(28, 'p000', 'a001', 'I was sick'),
(30, 'p000', 'a000', 'I was sick');

-- --------------------------------------------------------

--
-- Table structure for table `teacher`
--

CREATE TABLE `teacher` (
  `teacher_id` varchar(20) NOT NULL,
  `teacher _name` varchar(20) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `teacher`
--

INSERT INTO `teacher` (`teacher_id`, `teacher _name`) VALUES
('t000', 'Kalsam'),
('t001', 'Jamal'),
('t003', 'Kalungi');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `assignments`
--
ALTER TABLE `assignments`
  ADD PRIMARY KEY (`assignment_id`);

--
-- Indexes for table `attempt`
--
ALTER TABLE `attempt`
  ADD PRIMARY KEY (`attempt_id`);

--
-- Indexes for table `pupils`
--
ALTER TABLE `pupils`
  ADD PRIMARY KEY (`pupil_code`);

--
-- Indexes for table `requests`
--
ALTER TABLE `requests`
  ADD PRIMARY KEY (`request_id`),
  ADD KEY `pupil_code` (`pupil_code`),
  ADD KEY `assignment_id` (`assignment_id`);

--
-- Indexes for table `teacher`
--
ALTER TABLE `teacher`
  ADD PRIMARY KEY (`teacher_id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `attempt`
--
ALTER TABLE `attempt`
  MODIFY `attempt_id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=19;

--
-- AUTO_INCREMENT for table `requests`
--
ALTER TABLE `requests`
  MODIFY `request_id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=31;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
