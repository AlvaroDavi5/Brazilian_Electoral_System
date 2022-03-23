#include "../include/utils.h"


Utils::Utils() {
	//// do nothing
}
Utils::~Utils() {
	//// do nothing
}

time_t Utils::parseStringToTime(const char *strDate) {
	struct tm date;
	int day, month, year;

	sscanf(strDate, "%d/%d/%d", &day, &month, &year);

	date.tm_mday = day;
	date.tm_mon = month - 1;
	date.tm_year = year - 1900;
	date.tm_hour = 0;
	date.tm_min = 0;
	date.tm_sec = 0;

	time_t time = mktime(&date);

	return time;
}
const string Utils::parseTimeToString(const time_t time) {
	struct tm *date;
	char strDate[12];

	date = localtime(&time);
	strftime(strDate, 12, "%d/%m/%Y", date);

	return string(strDate);
}

int Utils::countColumns(string row) {
	int count = 0;

	for (int i = 0; i < (int)row.length(); i++) {
		if (row[i] == ',') {
			count++;
		}
	}
	count += 1;

	return count;
}

int Utils::olderThan(time_t d1, time_t d2) {
	const auto diff = difftime(d1, d1);

	if (diff > 0.0) {
		return -1;
	}
	else if (diff == 0.0) {
		return 0;
	}
	else {
		return 1;
	}
}

int Utils::calculateAge(time_t birthDate, time_t currentDate) {
	int age = 0;
	int year = 0;
	int month = 0;
	int day = 0;

	struct tm *currentDateStruct = localtime(&currentDate);

	year = currentDateStruct->tm_year - localtime(&birthDate)->tm_year;
	month = currentDateStruct->tm_mon - localtime(&birthDate)->tm_mon;
	day = currentDateStruct->tm_mday - localtime(&birthDate)->tm_mday;

	if (month < 0 || (month == 0 && day < 0)) {
		year--;
	}
	age = year;

	return age;
}
