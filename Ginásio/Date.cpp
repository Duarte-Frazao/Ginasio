#include <utility>
#include <string>
#include <iomanip>
#include "ErrorClasses.h"
#include "Date.h"

Date::Date(int hour, int min, int weekDay){
	if (weekDay < 1 || weekDay > 7 || hour < 0 || hour > 24 || min < 0 || min > 60)
		throw ErrorDate("Invalid date inserted");

	this->hour = hour;
	this->min = min;
	this->weekDay = weekDay;
}

Date::Date(){
	int hrs, min, wkd;
	std::cout << "Write date in format (Weekday Hrs Min): ";
	std::cin >> wkd >> hrs >> min;

	try{
		*this = Date(hrs, min, wkd);
	}
	catch(ErrorDate &e){
		throw e;
	}
}


bool operator<(const Date & date1, const Date & date2){
	if(date1.weekDay < date2.weekDay ||
			(date1.weekDay == date2.weekDay && date1.hour < date2.hour) ||
					(date1.weekDay == date2.weekDay && date1.hour == date2.hour && date1.min < date2.min))
		return true;

	else return false;
}

bool operator==(const Date & date1, const Date & date2){
	if(date1.weekDay == date2.weekDay && date1.hour == date2.hour && date1.min == date2.min)
		return true;

	else return false;
}

std::string weekDay_to_string(int weekDay){
	switch (weekDay){
	case 1: return "Monday";
	case 2: return "Tuesday";
	case 3: return "Wednesday";
	case 4: return "Thursday";
	case 5: return "Friday";
	case 6: return "Saturday";
	case 7: return "Sunday";
	default: return "";
	}
}

std::ostream & operator<<(std::ostream &out , const Date &date){
	out << std::left <<weekDay_to_string(date.weekDay) << ", " << std::right;
	out << std::setfill('0') << std::setw(2) << date.hour << ":" << std::setw(2)<<date.min << std::endl;
	return out;
}
