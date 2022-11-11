#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, num;
	int cnt = 1;
	stack<int> s;
	vector<string> v;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> num;

		while (cnt <= num)
		{
			s.push(cnt);
			cnt++;
			v.push_back("+");
		}

		if (s.top() == num)
		{
			s.pop();
			v.push_back("-");
		} else {
			cout << "NO\n";
			return (0);
		}
	}

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << "\n";
	}
}