#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;
	stack<char> s;
	int temp = 1;
	int answer = 0;
	
	cin >> str;

	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '(')
		{
			temp *= 2;
			s.push(str[i]);
		}
		else if (str[i] == '[')
		{
			temp *= 3;
			s.push(str[i]);
		}
		else if (str[i] == ')')
		{
			if (s.empty() || s.top() != '(')
			{
				cout << 0 << "\n"; 
				return (0);	
			}
			else if (str[i - 1] == '(') // ()로 닫힌 경우
			{
				answer += temp;
				temp /= 2;
				s.pop();
			} else { // 이미 이전에 계산이 끝난 경우
				temp /= 2;
				s.pop();
			}
		}
		else if (str[i] == ']')
		{
			if (s.empty() || s.top() != '[')
			{
				cout << 0 << "\n";
				return (0);	
			}
			else if (str[i - 1] == '[') // []로 닫힌 경우
			{
				answer += temp;
				temp /= 3;
				s.pop();
			} else { // 이미 이전에 계산이 끝난 경우
				temp /= 3;
				s.pop();
			}
		}
	}
	if (!s.empty()) 
	{
		cout << 0 << "\n";
		return (0);
	}
	cout << answer << "\n";
}