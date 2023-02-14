#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

string str;
int N;
stack<char> s1;
stack<char> s2;

int main()
{
    ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> str;
    for (int i = 0; i < str.size(); i++)
        s1.push(str[i]);
    
    cin >> N;

    char c;
    char p;
    for (int i = 0; i < N; i ++)
    {
        cin >> c;

        if (c == 'L')
        {
            if (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        } else if (c == 'D')
        {
            if (!s2.empty())
            {
                s1.push(s2.top());
                s2.pop();
            }
        } else if (c == 'B')
        {
            if (!s1.empty())
                s1.pop();
        } else if (c == 'P')
        {
            cin >> p;
            s1.push(p);
        }
    }

    string answer;
    int n;
    n = s1.size();
    for (int i = 0; i < n; i++)
    {
        answer += s1.top();
        s1.pop();
    }
    reverse(answer.begin(), answer.end());
    n = s2.size();
    for (int i = 0; i < n; i++)
    {
        answer += s2.top();
        s2.pop();
    }
    
    cout << answer;
}