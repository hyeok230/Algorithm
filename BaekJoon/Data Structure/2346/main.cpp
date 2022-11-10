#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, num;
	stack<int> s1;
	stack<int> s2;
	vector<int> v;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> num;
		v.push_back(num);
		s1.push(i + 1);
	}

	for (int i = 0; i < n; i++)
	{
		
	}


}