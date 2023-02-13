#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int n1, n2, n3, n4, n5;

    cin >> n1 >> n2 >> n3 >> n4 >> n5;

    int sum = pow(n1, 2) + pow(n2, 2) + pow(n3, 2) + pow(n4, 2) + pow(n5, 2);

    cout << sum % 10;
}