// wordTime.cpp : Defines the entry point for the console application.
// Program to print the time in words.

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

static const char *_hour[] = { "twelve", "one", "two", "three", "four", "five", "six", "seven", "eigth", "nine", "ten", "eleven", "twelve" };
static const char *_singles[] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eigth", "nine" }; // vector para los numeros del zero al 9
static const char *_teens[] = { "err", "eleven", "twelve", "thirteen", "fourteen", "quarter", "sixteen", "seventeen", "eigthteen", "nineteen" };
static const char *_doubles[] = { "err", "ten", "twenty", "thirty"}; // vector para las decenas
static const char *_times[] = { "o' clock", "past", "to", "half" };

string getTime(int _m) {
	string time;

	if (_m == 0) {
		time = _times[0];
	}
	else if (_m > 0 && _m <= 29) {
		time = _times[1];
	}
	else if (_m == 30) {
		time = _times[3];
		time = time + " " + _times[1];
	}
	else if (_m >= 31 && _m < 60) {
		time = _times[2];
	}

	return time;
}

string getMinute(int _m) {
	string minute;

	if (_m >= 31) {
		_m = 60 - _m;
	}

	if (_m > 0 && _m <= 29) {
		if (1 <= _m && _m <= 9) {
			minute = _singles[_m];
		}
		else if (10 < _m && _m <= 19) {
			minute = _teens[_m % 10];
		}
		else if (20 < _m && _m <= 29) {
			minute = _doubles[_m / 10];
			minute = minute + _singles[_m % 10];
		}
		else if (_m == 10 || _m == 20) {
			minute = _doubles[_m / 10];
		}
	}

	return minute;
}

string getHour(int _h, int _m) {
	string hour;

	if (_m >= 31) {
		if (_m == 60) {
			_h = 0;
		}
		else {
			_h++;
			if (_h > 12) {
				_h = _h - 12;
			}
		}
	}

	hour = _hour[_h];
	return hour;
}

string timeInWords(int h, int m) {
	string time = getTime(m);
	string minute = getMinute(m);
	string hour = getHour(h, m);
	string timeOutput;

	if (m == 0) {
		timeOutput = hour + " " + time;
	}
	else if (m == 30) {
		timeOutput = time + " " + hour;
	}
	else if ((0 < m && m < 30) || (30 < m && m < 60)) {
		if (m == 15 || m == 45) {
			timeOutput = minute + " " + time + " " + hour;
		}
		else {
			timeOutput = minute + " minutes " + time + " " + hour;
		}
	}

	return timeOutput;
}

int main()
{
	int hours, minutes;

	cin >> hours;
	cin >> minutes;

	string result = timeInWords(hours, minutes);
	cout << result << endl;
    return 0;
}

