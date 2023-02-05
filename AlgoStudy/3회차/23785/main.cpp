#include <iostream>
#include <string>
#include <stack>

using namespace std;

int y;
int list[10] = {0};
stack<int> s;

void fact(int n) {
	list[0] = 1;
	for (int i = 1; i <= n; ++i) {
         list[i] = i * list[i - 1];
    }
}

int main()
{
    ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> y;

	fact(9);

	for (int i = 0; i <= 9; i++)
	{
		if (list[i] == y)
		{
			cout << i;
			return 0;
		}
	}

	while (y)
	{
		for (int i = 9; i >= 1; i--)
		{
			if (y >= list[i])
			{
				y -= list[i];
				s.push(i);
				break ;
			}
		}
	}
	int n = s.size();
	for (int i = 0; i < n; i++)
	{
		cout << s.top();
		s.pop();
	}
}