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
			int countColumns(string row);

			void readFile(string path, Election eleInfo);

			int olderThan(time_t d1, time_t d2);

			int calculateAge(time_t birthTime, time_t currentTime);
	};

#endif // UTILS_H
