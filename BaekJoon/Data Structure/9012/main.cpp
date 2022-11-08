#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
	int n;
	cin >> n;

	
	stack<char> st;

	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		
		bool flag = true;

		for (int j = 0; j < str.size(); j++)
		{
			if (str[j] == '(')
				st.push(str[j]);
			else
			{
				if (st.empty())
				{
					flag = false;
					break ;
				}
				else
				{
					st.pop();
				}
			}
		}
		if (!flag)
		{
			cout << "NO" << endl;
			continue;
		}

		if (st.empty())
		{
			cout << "YES" << endl;
		}
		else 
		{
			cout << "NO" << endl;
		}

		while(!st.empty()) st.pop();
	}
}