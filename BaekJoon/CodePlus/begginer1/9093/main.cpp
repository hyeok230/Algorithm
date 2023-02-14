#include <iostream>
#include <string>
#include <stack>

using namespace std;

int N;
stack<char> s;

int main()
{
    ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> N;
    cin.ignore();
    while (N--)
    {
        string str;
        getline(cin, str);
        str += " ";
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == ' ')
            {
                while (!s.empty())
                {
                    cout << s.top();
                    s.pop();
                }
                cout << str[i];
                continue ;
            }
            s.push(str[i]);
        }
        cout << "\n";
    }
}