#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string X;
string result;

int calculate(int start, int end)
{
    int num = end - start;

    int a = num / 4;
    int left = num % 4;
    int b = 0;
    while(a >= 0)
    {
        if (left % 2 == 0)
        {
            b = left / 2;
            break;   
        }
        else {
            a--;
            left = num / 4;
        }
    }
    if (num == 4 * a + 2 * b)
    {
        for (int i = 0; i < a; i++)
        {
            result += "AAAA";
        }
        for (int i = 0; i < b; i++)
        {
            result += "BB";
        }
        return (1);
    }
    else {
        cout << "-1";
        return (0);
    }
}

int main()
{
    ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> X;

    int i = 0;
    int start = 0;
    while (X[i])
    {
        if (i == X.size() - 1 && X[i] != '.')
        {
            if (calculate(start, i + 1) == 0)
                return (0);
        }
        if (X[i] == '.')
        {
            if (calculate(start, i) == 0)
                return (0);
            while (X[i] == '.')
            {
                result += ".";
                i++;
            }
            start = i;
            i--;
        }
        i++;
    }
    cout << result;
}