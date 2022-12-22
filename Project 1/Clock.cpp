#include "Clock.h"
#include <stdexcept>

using namespace std;

Clock::Clock(int hours, int minutes, int seconds) {

    if (hours > 23 || hours < 0) {
        throw std::invalid_argument("Hours are out of range! Range is 0 - 23.");
    }
    if (minutes > 59 || minutes < 0) {
        throw std::invalid_argument("Minutes are out of range! Range is 0 - 59.");
    }
    if (seconds > 59 || seconds < 0) {
        throw std::invalid_argument("Seconds are out of range! Range is 0 - 59.");
    }

    this->hours = hours;
    this->minutes = minutes;
    this->seconds = seconds;
}

//Adds an hour to the clock.
void Clock::addHour() {
    if (hours == 23) {
        hours = 0;
    }
    else {
        hours++;
    }
}

//Adds a minute to the clock.
void Clock::addMinute() {
    if (minutes == 59) {
        minutes = 0;
        addHour();
    }
    else {
        minutes++;
    }
}

//Adds a second to the clock.
void Clock::addSecond() {
    if (seconds == 59) {
        seconds = 0;
        addMinute();
    }
    else {
        seconds++;
    }
}

//Combines hours, minutes, and seconds into a 24-hour format.
//@returns - A string containing time in a 24-hour form.
string Clock::get24HourFormat() {
    string twentyFourHourTime;

    twentyFourHourTime = pad(hours) + ":" + pad(minutes) + ":" + pad(seconds);

    return twentyFourHourTime;
}

//Combines hours, minutes, and seconds into a 12-hour format.
//@returns - A string containing time in a 12-hour format.
string Clock::get12HourFormat() {
    string twelveHourTime;
    int tempHours;

    if (hours == 0) {
        tempHours = 12;
    }
    else if (hours > 12) {
        tempHours = hours - 12;
    }
    else {
        tempHours = hours;
    }
    twelveHourTime = to_string(tempHours) + ":" + pad(minutes) + ":" + pad(seconds) + " " + getSuffix();

    return twelveHourTime;
}


//Figures out if the time suffix should be AM or PM. 
//@returns - A string containing AM or PM depending on hours.
string Clock::getSuffix() {
    string suffix;

    if (hours < 12) {
        suffix = "AM";
    }
    else {
        suffix = "PM";
    }

    return suffix;
}

//Adds a preceding 0 to an int value if the value is less than ten. 
//@param value - int value
//@returns - string value that contains input int with preceding 0 if the input is less than 10. 
string Clock::pad(int value) {
    string padded;

    if (value < 10) {
        padded = "0" + to_string(value);
    }
    else {
        padded = to_string(value);
    }

    return padded;
}