#include <iostream>
#include <string>
using namespace std;

class invalidDay // class to handle exceptions about day
{
	string msg;
public:
	invalidDay() {
		msg = "Day input is wrong";
	}
	void showException() {
		cout << msg << endl;
	}
};
class invalidMonth // class to handle exceptions about month
{
	string msg;
public:
	invalidMonth() {
		msg = "Month input is wrong";
	}
	void showException() {
		cout << msg << endl;
	}
};

//function to check if year is a leap or not
bool isLeapYear(int year)
{
	return ((year % 400 == 0 || year % 100 != 0) && (year % 4 == 0));
}

//function to show the number of days
int getNumberOfDays(int month, int year)
{
	switch (month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		return 31;
		break;
	case 2:
		if (isLeapYear(year)) {
			return 29;
		}
		else
			return 28;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		return 30;
		break;
	}
}

//function to validate the date
bool validateDate(int day, int month, int year)
{
	int num_days;
	bool isALeapYear = isLeapYear(year);

	if (month < 1 || month > 12)
		throw invalidMonth();
	if (isALeapYear == true) {
		num_days = getNumberOfDays(month, year);
		if (day < 1 || day > num_days)
			throw invalidDay();
	}
	else
	{
		num_days = getNumberOfDays(month, year);
		if (day < 1 || day > num_days)
			throw invalidDay();
	}
}

//main function
int main()
{
	string date;
	int day, month, year;
	string months[12] = { "January", "February","March","April","May","June",
		"July","August","September","October","November","December" };
	//Exception Handling
	try
	{
		cout << "Enter date in the format dd-mm-yyyy" << endl;
		cin >> date;
		int char1 = date.find_first_of('-');
		int char2 = date.find_last_of('-');
		day = stoi(date.substr(0, char1));
		month = stoi(date.substr(char1 + 1, char2));
		year = stoi(date.substr(char2 + 1));

		validateDate(day, month, year);

		//Display output
		cout << "\nDate of Birth " << months[month - 1] << " " << day << "," << year << endl;
	}

	//Catch statement for invalid day
	catch (invalidDay id) {
		id.showException();
	}
	//Catch statement for invalid month
	catch (invalidMonth im) {
		im.showException();
	}

	system("pause");
	return 0;
}
