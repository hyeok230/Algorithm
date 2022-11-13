#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int cnt = 0;
	int index;
	string str;
	stack< pair<char, int> > s;

	cin >> str;

	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '(')
		{
			s.push(make_pair(str[i], i));
		}
		else {
			index = s.top().second;
			s.pop();
			if (i - index == 1)
			{
				cnt += s.size();
			}
			else {
				cnt += 1;
			}
		}
	}
	cout << cnt;
}