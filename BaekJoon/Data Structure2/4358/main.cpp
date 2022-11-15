#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int num = 0;
	string str;
	map<string, float> m;

	while (getline(cin, str))
	{
		num++;
		if (m.find(str) != m.end())
		{
			m[str] += 1;	
		} else {
			m.insert(make_pair(str, 1));
		}
	}
	cout << fixed;
	cout.precision(4);
	for (auto it = m.begin(); it != m.end(); it++)
	{
		cout << it->first << " " << (it->second / num) * 100 << "\n";
	}
}