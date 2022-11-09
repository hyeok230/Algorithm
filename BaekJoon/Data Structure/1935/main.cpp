#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, index; 
    double num, a, b, c;
    string str;
    vector<int> v;
    stack<double> s;

    cin >> n;
    cin >> str;

    for (int i = 0; i < n; i++)
    {
        cin >> num;
        v.push_back(num);
    }

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            index = str[i] - 'A';
            s.push(v[index]);
        } else {
            if (!s.empty())
            {
                b = s.top();
                s.pop();
                a = s.top();
                s.pop();
                if (str[i] == '+')
                {
                    c = a + b;
                    s.push(c);
                } else if (str[i] == '-')
                {
                    c = a - b;
                    s.push(c);
                } else if (str[i] == '/')
                {
                    c = a / b;
                    s.push(c);
                } else if (str[i] == '*')
                {
                    c = a * b;
                    s.push(c);
                }
            }
        }
    }
    cout << fixed;
    cout.precision(2);
    cout << s.top() << "\n";
}