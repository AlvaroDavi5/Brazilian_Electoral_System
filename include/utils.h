#ifndef UTILS_H

	#define UTILS_H

	#include <iostream>
	#include <string>
	#include <ctime>

	using namespace std;


	class Utils {
		public:
			// ! Constructor(s) and Destructor
			~Utils();


			// ? Member Functions
			time_t parseStringToTime(const char *strDate);
			const string parseTimeToString(const time_t time);

			int countColumns(string row);

			int olderThan(time_t d1, time_t d2);

			int calculateAge(time_t birthTime, time_t currentTime);
	};

#endif // UTILS_H
