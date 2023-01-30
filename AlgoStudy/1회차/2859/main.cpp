#include <iostream>
#include <algorithm>
#include <string>
#include <numeric>
using namespace std;

string star1;
string star2;
string time1;
string time2;
int s1;
int s2;
int t1;
int t2;
string week[7] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};


int main()
{
    ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> star1;
	cin >> star2;
	cin >> time1;
	cin >> time2;

	s1 = stoi(star1.substr(0, 2)) * 60 + stoi(star1.substr(3,2));
	s2 = stoi(star2.substr(0, 2)) * 60 + stoi(star2.substr(3,2));
	t1 = stoi(time1.substr(0, 2)) * 60 + stoi(time1.substr(3,2));
	t2 = stoi(time2.substr(0, 2)) * 60 + stoi(time2.substr(3,2));
	
	for (int i = 0; i < 1440; i++)
	{
		if (s1 == s2)
		{
			int date = s1 / (24 * 60) % 7;
			cout << week[date] << "\n";
			s1 %= (24 * 60);
			int time = s1 / 60;
			if (time < 10)
				cout << "0";
			cout << time;
			s1 %= 60;
			cout << ":";
			if (s1 < 10)
				cout << "0";
			cout << s1;
			return (0);
		}
		if (s1 < s2)
			s1 += t1;
		else
			s2 += t2;
	}
	cout << "Never";
}