//Implementation File for the class clockType
    
#include <iostream> 
#include "clockType.h" 

using namespace std;

//
// clockType Accessors/Mutators
//
void clockType::setTime(int hours, int minutes, int seconds)
{
    if (0 <= hours && hours < 24)
        hr = hours;
    else 
        hr = 0;

    if (0 <= minutes && minutes < 60)
        min = minutes;
    else 
        min = 0;

    if (0 <= seconds && seconds < 60)
        sec = seconds;
    else 
        sec = 0;
}

void clockType::getTime(int& hours, int& minutes, int& seconds) const
{
    hours = hr;
    minutes = min;
    seconds = sec;
}

//
// Increment
//
void clockType::incrementHours()
{
    hr++;
    if (hr > 23)
        hr = 0;
}

void clockType::incrementMinutes()
{
    min++;
    if (min > 59)
    {
        min = 0;
        incrementHours();
    }
}

void clockType::incrementSeconds()
{
    sec++;

    if (sec > 59)
    {
        sec = 0;
        incrementMinutes();
    }
}

//
// clockType default Time
//
void clockType::printTime() const
{
    if (hr < 10)
        cout << "0";
    cout << hr << ":";

    if (min < 10)
        cout << "0";
    cout << min << ":";

    if (sec < 10)
        cout << "0";
    cout << sec;
}

//
// clockType Boolean 
//
bool clockType::equalTime(const clockType& otherClock) const
{
    return (hr == otherClock.hr 
            && min == otherClock.min 
            && sec == otherClock.sec);
}

//
// clockType int variables
//
clockType::clockType(int hours, int minutes, int seconds)
{
    if (0 <= hours && hours < 24)
        hr = hours;
    else 
        hr = 0;

    if (0 <= minutes && minutes < 60)
        min = minutes;
    else 
        min = 0;

    if (0 <= seconds && seconds < 60)
        sec = seconds;
    else 
        sec = 0;
}

clockType::clockType()  //default constructor
{
    hr = 0;
    min = 0;
    sec = 0;
}

//
// extClockType code
//

//
// sets the timeZone variable to the user input
// set tz = 0 if timeZone is less than -12 or
// greater than 12
//
void extClockType::setTimeZone(int timeZone)
{
	if (timeZone >= -12 && timeZone <= 12)
		tz = timeZone;
	else
		tz = 0;
}

//
// Get the timeZone and calculate the hours based on the timeZone
// If the timeZone is less than 1, then 0 = 12, etc.
// if the timeZone is greater than 12, then 13 = 1, etc.
// If the timeZone input is greater than 12 or less than -12, then tz = 0
//
int extClockType::getTimeZone(int hours, int timeZone)
{
	if (timeZone / (timeZone * -1) == -1)
	{
		timeZone = hours - (tz * -1);
		if (timeZone < 1)
			if (timeZone == 0)
			{
				timeZone = 12;
			}
			else
			{
				timeZone = timeZone + 12;
				return timeZone;
			}
		return timeZone;
	}
	if (timeZone > 0 && timeZone <= 12)
	{
		timeZone = hours + tz;
		if (timeZone > 12)
			timeZone = timeZone - 12;
			return timeZone;
		return timeZone;
	}
	else
	{
		tz = 0;
		return timeZone;
	}
}

//
// Unused code (for now)
// Prints the user input for timeZone, will not
// be implemented yet
//
void extClockType::printTimeZone()
{
	cout << "place holder" << endl;
}

extClockType::extClockType()  // extClockType constructor
{
	tz = 0;
}