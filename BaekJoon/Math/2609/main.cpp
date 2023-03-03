#include <iostream>

using namespace std;

int gcd(int a, int b)
{
    int c = a % b;
    while (c != 0)
    {
        a = b;
        b = c;
        c = a % b;
    }
    return b;
}

int lcm(int a, int b)
{
    return (a * b) / gcd(a, b);
}

int main()
{
    ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int a, b;
    cin >> a >> b;

    int ans1 = gcd(a, b);
    int ans2 = lcm(a, b);

    cout << ans1 << "\n" << ans2;
}