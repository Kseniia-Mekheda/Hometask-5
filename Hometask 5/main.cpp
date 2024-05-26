#include "forecast.h"

int main() {
	vector<Forecast> forecast; 
	ifstream fin("forecast.txt");
	copy(istream_iterator<Forecast>(fin), istream_iterator<Forecast>(), back_inserter(forecast)); 
	sort(forecast.begin(), forecast.end());
	cout << "Container of forecasts: " << endl;
	copy(forecast.cbegin(), forecast.cend(), ostream_iterator<Forecast>(cout, ""));
	cout << endl;
	system("pause");

	cout << "Enter month you want to check: ";
	Month month; 
	cin >> month;
	InfoForMonth(forecast, month);
	cout << endl;
	system("pause");

	vector<Forecast> withoutRain; 
	copy_if(forecast.cbegin(), forecast.cend(), back_inserter(withoutRain), [](const Forecast& F)
		{
			return F.getPrecipitation() == 0;
		});
	
	if (withoutRain.empty())
	{
		cout << "There are no days without rain." << endl;
	}
	else
	{
		sort(withoutRain.begin(), withoutRain.end(), [](const Forecast& First, const Forecast& Second)
			{
				return First.getTemperature() < Second.getTemperature();
			}); 

		cout << "We have " << withoutRain.size() << " day(s) without rain. Here is some info about it: " << endl;
		copy(withoutRain.cbegin(), withoutRain.cend(), ostream_iterator<Forecast>(cout, ""));
		cout << endl;

		cout << "Coldest rainless day: " << '\n' << withoutRain.front() << endl;
		cout << "Warmest rainless day: " << '\n' << withoutRain.back() << endl;
	}
	system("pause");
	cout << endl;
	
	vector<int> TempForDay;
	cout << "Enter the day for our research: ";
	string day;
	cin >> day; 

	transform(forecast.cbegin(), forecast.cend(), back_inserter(TempForDay), [&day](const Forecast& F)
		{
			return F.getDayName() == day ? F.getTemperature() : -100;
		});
	TempForDay.erase(remove(TempForDay.begin(), TempForDay.end(), -100), TempForDay.end());
	sort(TempForDay.begin(), TempForDay.end());
	auto it = unique(TempForDay.begin(), TempForDay.end());
	TempForDay.resize(distance(TempForDay.begin(), it));
	copy(TempForDay.cbegin(), TempForDay.cend(), ostream_iterator<int>(cout, " "));
	
	return 0;
}