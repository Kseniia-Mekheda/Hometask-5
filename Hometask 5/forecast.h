#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

enum class Month
{
	JANUARY = 1,
	FEBRUARY, 
	MARCH,
	APRIL,
	MAY,
	JUNE,
	JULY,
	AUGUST, 
	SEPTEMBER,
	OCTOBER,
	NOVEMBER,
	DECEMBER,
	UNDEFINED
};

istream& operator>>(istream& in, Month& M);
ostream& operator<<(ostream& out, const Month& M);

class Forecast {
private:
	string day_name;
	int day_number;
	Month day_month; 
	int day_temperature;
	int day_precipitation; 

public:
	Forecast(string name = " ", int number = 0, Month month = Month::UNDEFINED, int temperature = 0, int precipitation = 0);
	Forecast(const Forecast& C);
	~Forecast(); 

	string getDayName() const;
	Month getMonth() const;
	int getTemperature() const;
	int getPrecipitation() const; 

	void setTemperature(int newTemperature);
	void setPrecipitation(int newPrecipitation);

	void readFrom(istream& in);
	void writeTo(ostream& out) const; 

	bool operator<(const Forecast& F) const;
};

istream& operator>>(istream& in, Forecast& F);
ostream& operator<<(ostream& out, const Forecast& F); 

void InfoForMonth(vector<Forecast> f, const Month& M); 