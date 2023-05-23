#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N;

int main() {
    ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> N;

    for (int i = 1; i <= N; i++) {
        int ans = i;
        int num = i;
        int n = i;
        while (n) {
            num += (n % 10);
            n /= 10;
        }

        if (num == N) {
            cout << ans;
            return 0;
        }
    }

    cout << 0;
    return 0;
}