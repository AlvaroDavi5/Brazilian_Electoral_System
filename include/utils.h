#ifndef UTILS_H

	#define UTILS_H

	#include <iostream>
	#include <string>
	#include <list>
	#include <ctime>
	#include <locale>
	#include "./election.h"

	using namespace std;


	class Utils {
		public:
			// ! Constructor(s) and Destructor
			~Utils();


			// ? Member Functions
			int countColumns(String row);

			void readFile(String path, Election eleInfo);

			int olderThan(Date d1, Date d2);

			int calculateAge(time_t birthTime, time_t currentTime);
	};

#endif // UTILS_H
