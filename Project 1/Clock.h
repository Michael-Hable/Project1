#pragma once
#include <string>

class Clock
{
public:
	Clock(int hours, int minutes, int seconds);
	void addHour();
	void addSecond();
	void addMinute();
	std::string get12HourFormat();
	std::string get24HourFormat();

private:
	int hours;
	int minutes;
	int seconds;
	std::string pad(int);
	std::string getSuffix();
};