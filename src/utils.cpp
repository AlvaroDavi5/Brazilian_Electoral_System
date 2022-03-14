#include "../include/utils.h"


int Utils::countColumns(string row) {
	int count = 0;

	for (int i = 0; i < row.length(); i++) {
		if (row[i] == ',') {
			count++;
		}
	}
	count += 1;

	return count;
}

void Utils::readFile(string path, Election eleInfo) {
	string line = "";
	bool firstLine = true;
	ifstream file(path);
	if (!file.is_open()) {
		cout << "Error opening file" << endl;
	}

	while (!file.eof())
	{
		if (line != NULL)
		{
			if (firstLine && line != "")
			{
				if (countColumns(line) == 4)
				{
					eleInfo.setEntity('p');
				}
				else
				{
					eleInfo.setEntity('c');
				}
				firstLine = false;
			}
			else
			{
				eleInfo.addData(line);
			}
		}
		else
		{
			break;
		}
		getline(file, line);
	}

	file.close();
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

	struct tm *birthDateStruct = localtime(&birthDate);
	struct tm *currentDateStruct = localtime(&currentDate);

	year = currentDateStruct->tm_year - birthDateStruct->tm_year;
	month = currentDateStruct->tm_mon - birthDateStruct->tm_mon;
	day = currentDateStruct->tm_mday - birthDateStruct->tm_mday;

	if (month < 0 || (month == 0 && day < 0)) {
		year--;
	}
	age = year;

	return age;
}
