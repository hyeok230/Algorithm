#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string X;
string result;
int cnt;

int main()
{
    ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> X;

    X += ' ';

    for (int i = 0; i < X.size() - 1; i++)
    {
        if (X[i] == 'X') cnt++;

        if (X[i] == '.')
        {
            result += '.';
            if (cnt % 2 != 0) break;
            else cnt = 0;
        }

        if (cnt == 2 && X[i + 1] != 'X')
        {
            result += "BB";
            cnt = 0;
        }   
        if (cnt == 4)
        {
            result += "AAAA";
            cnt = 0;
        }
            
    }

    if (cnt % 2 != 0) 
    {
        cout << -1;
        return (0);
    }
    cout << result;
}