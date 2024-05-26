#include "forecast.h"

istream& operator>>(istream& in, Month& M)
{
	string m;
	in >> m;
	if (m == "January")
		M = Month::JANUARY;
	else if (m == "February")
		M = Month::FEBRUARY;
	else if (m == "March")
		M = Month::MARCH;
	else if (m == "April")
		M = Month::APRIL;
	else if (m == "May")
		M = Month::MAY;
	else if (m == "June")
		M = Month::JUNE;
	else if (m == "July")
		M = Month::JULY;
	else if (m == "August")
		M = Month::AUGUST;
	else if (m == "September")
		M = Month::SEPTEMBER;
	else if (m == "October")
		M = Month::OCTOBER;
	else if (m == "November")
		M = Month::NOVEMBER;
	else if (m == "December")
		M = Month::DECEMBER;
	else
		M = Month::UNDEFINED;
	return in;
}

ostream& operator<<(ostream& out, const Month& M)
{
	switch (M)
	{
	case Month::JANUARY:
		cout << "January";
		break;

	case Month::FEBRUARY:
		cout << "February";
		break;

	case Month::MARCH:
		cout << "March";
		break;

	case Month::APRIL:
		cout << "April";
		break;

	case Month::MAY:
		cout << "May";
		break;

	case Month::JUNE:
		cout << "June";
		break;

	case Month::JULY:
		cout << "July";
		break;

	case Month::AUGUST:
		cout << "August";
		break;

	case Month::SEPTEMBER:
		cout << "September";
		break;

	case Month::OCTOBER:
		cout << "October";
		break;

	case Month::NOVEMBER:
		cout << "November";
		break;

	case Month::DECEMBER:
		cout << "December";
		break;
	default:
		break;
	}
	return out;
}

Forecast::Forecast(string name, int number, Month month, int temperature, int precipitation)
	:day_name(name),
	day_number(number),
	day_month(month),
	day_temperature(temperature),
	day_precipitation(precipitation)
{}

Forecast::Forecast(const Forecast& C)
	:day_name(C.day_name),
	day_number(C.day_number),
	day_month(C.day_month),
	day_temperature(C.day_temperature),
	day_precipitation(C.day_precipitation)
{}

Forecast::~Forecast() {}

string Forecast::getDayName() const
{
	return day_name;
}

Month Forecast::getMonth() const
{
	return day_month;
}

int Forecast::getTemperature() const
{
	return day_temperature;
}

int Forecast::getPrecipitation() const
{
	return day_precipitation;
}

void Forecast::setTemperature(int newTemperature)
{
	day_temperature = newTemperature;
}

void Forecast::setPrecipitation(int newPrecipitation)
{
	day_precipitation = newPrecipitation;
}

void Forecast::readFrom(istream& in)
{
	in >> day_name >> day_number >> day_month >> day_temperature >> day_precipitation;
}

void Forecast::writeTo(ostream& out) const
{
	out << day_name << ", ";
	if (day_number == 01 || day_number > 20 && day_number % 10 == 1)
	{
		out << day_number << "st ";
	}
	else if (day_number == 02 || day_number > 20 && day_number % 10 == 2)
	{
		out << day_number << "nd ";
	}
	else if (day_number == 03 || day_number > 20 && day_number % 10 == 3)
	{
		out << day_number << "rd ";
	}
	else
	{
		out << day_number << "th ";
	}

	out << "of " << day_month << ':' << '\n' << " Temperature: " << day_temperature << "C" << '\n'
		<< " Recipitation: " << day_precipitation << "mm" << endl;
}

bool Forecast::operator<(const Forecast& F) const
{
	if (day_month < F.day_month || (day_month == F.day_month && day_number < F.day_number))
	{
		return true;
	}
	else
	{
		return false;
	}
}

istream& operator>>(istream& in, Forecast& F)
{
	F.readFrom(in);
	return in;
}

ostream& operator<<(ostream& out, const Forecast& F)
{
	F.writeTo(out);
	return out;
}

void InfoForMonth(vector<Forecast> f, const Month& M)
{
	int counterWithoutRain = 0;
	int amountOfPrecipitation = 0;

	for_each(f.begin(), f.end(), [&M, &counterWithoutRain, &amountOfPrecipitation](const Forecast& F)
		{
			if (F.getMonth() == M)
			{
				if (F.getPrecipitation() == 0)
				{
					++counterWithoutRain;
				}
				else
				{
					amountOfPrecipitation += F.getPrecipitation();
				}
			}
		});

	cout << "In " << M << " we will have " << counterWithoutRain << " day(s) without rain and "
		<< amountOfPrecipitation << "mm of precipitation" << endl;
}