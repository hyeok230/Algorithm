#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;

int main()
{
    ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> N;

    int a = N / 5;
    int b;
    int left = N - 5 * a;

    while (a >= 0)
    {
        if (left % 2 == 0)
        {
            b = left / 2;
            break ;
        }
        else {
            a--;
            left = N - 5 * a;
        }
    }

    if (5 * a + 2 * b == N)
        cout << a + b;
    else 
        cout << "-1";
}