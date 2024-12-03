SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET GLOBAL time_zone = "+00:00";
SET SESSION time_zone = "+00:00";
START TRANSACTION;

SET NAMES utf8mb4;
SET CHARACTER SET utf8mb4;
SET character_set_connection = utf8mb4;
SET character_set_results = utf8mb4;
SET collation_connection = utf8mb4_general_ci;

DROP TABLE IF EXISTS `users`;
CREATE TABLE `users` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `full_name` varchar(128) NOT NULL,
  `email` varchar(255) NOT NULL,
  `password` varchar(255) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `email` (`email`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

INSERT INTO `users` (`full_name`, `email`, `password`) VALUES
('Aktar', 'aktar@gmail.com', '$2y$10$Jmf9Xk2y8m.fo3c/ZgKmzOrdIRkU05KSGLI0picKLEtr68ll7hjB.');

SET character_set_client = @saved_cs_client;
SET character_set_results = @saved_cs_results;
SET collation_connection = @saved_col_connection;

COMMIT;
