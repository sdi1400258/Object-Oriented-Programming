#include <ctime>
#include "date.h"

const unsigned int day_secs = 86400;

unsigned int Date::add_sec = 0;

//const Date

Date::Date()
{
	set();
}

Date::Date(int _s = 0)
{
	add_sec += _s;
	set(add_sec);
}

//Set xrono

void Date::set()
{
	time_t unix_time;
	time(&unix_time);
	infotime = *localtime(&unix_time);
}

//set xronos ++ deuterolepta

void Date::set(unsigned int s)
{
	time_t unix_time;
	time(&unix_time);
	unix_time += s;
	infotime = *localtime(&unix_time);
}

//set xronos 

void Date::set(const time_t& t)
{
	infotime = *localtime(&t);
}

void Date::sec_set(const int x)
{
	infotime.tm_sec = x;
}

void Date::min_set(const int x)
{
	infotime.tm_min = x;
}

void Date::hour_set(const int x)
{
	infotime.tm_hour = x;
}

void Date::day_set(const int x)
{
	infotime.tm_mday = x;
}

void Date::mon_set(const int x)
{
	infotime.tm_mon = x;
}

void Date::weekday_set(const int x)
{
	infotime.tm_wday = x;
}

void Date::yearday_set(const int x)
{
	infotime.tm_yday = x;
}

void Date::daylightsavingtime_set(const int x)
{
	infotime.tm_isdst = x;
}

int Date::get_sec() const
{
	return infotime.tm_sec;
}

int Date::get_min() const
{
	return infotime.tm_min;
}

int Date::get_hour() const
{
	return infotime.tm_hour;
}

int Date::get_day() const
{
	return infotime.tm_mday;
}

int Date::get_mon() const
{
	return infotime.tm_mon;
}

int Date::get_weekday() const
{
	return infotime.tm_wday;
}

int Date::get_yearday() const
{
	return infotime.tm_yday;
}

int Date::get_daylightsavingtime() const
{
	return infotime.tm_isdst;
}


const string Date::get_str(const char * format)
{
	strftime(buffer, DATE_STRINGBUFF, format, &infotime);
	return buffer;
}

void Date::print()
{
	
}