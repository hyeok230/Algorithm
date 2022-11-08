#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	int n;
	cin >> n;

	queue<int> q;

	int num;
	string str;
	for (int i = 0; i < n; i++)
	{
		cin >> str;
		if (str == "push")
		{
			cin >> num;
			q.push(num);
		}
		else if (str == "front")
		{
			if (q.size())
			{
				cout << q.front() << "\n";
			} 
			else
			{
				cout << -1 << "\n";
			}
		}
		else if (str == "back")
		{
			if (q.size())
			{
				cout << q.back() << "\n";
			}
			else 
			{
				cout << -1 << "\n";
			}
		}
		else if (str == "size")
		{
			cout << q.size() << "\n";
		}
		else if (str == "empty")
		{
			cout << q.empty() << "\n";
		}
		else if (str == "pop")
		{
			if (q.size())
			{
				cout << q.front() << "\n";
				q.pop();
			} 
			else 
			{
				cout << -1 << "\n";
			}
		}
	}

	return 0;
}
