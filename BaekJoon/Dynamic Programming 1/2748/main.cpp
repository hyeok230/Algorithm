#include <iostream>

using namespace std;

int N;

long long fibo_arr[100] = {0, 1, };

long long fibo(int n)
{
    if (n == 0 || n == 1)
        return (fibo_arr[n]);
    if (fibo_arr[n] == 0)
        fibo_arr[n] = fibo(n - 1) + fibo(n - 2);
    return (fibo_arr[n]);
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> N;

    cout << fibo(N);
}