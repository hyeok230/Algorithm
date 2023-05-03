#include <iostream>

using namespace std;

int N;

int main() {
    ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> N;

    if (N == 1)
    {
        cout << 1;
        return 0;
    }
    long long num = 1;
    int ret = 2;
    long long sumN = 6;
    while (N > num) {
        num += sumN;
        sumN += 6;
        ret++;
    }
    cout << ret - 1;
    return 0;
}