#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int T;

int main() {
    ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> T;

    for (int i = 0; i < T; i++) {
        int H, W, N;
        cin >> H >> W >> N;

        int num = N / H;
        int floor = 0;
        if (N - (H * num)) {
            floor = (N - (H * num)) * 100;
        } else {
            floor = H * 100;
        }
        if (N % H) {
            num++;
        }
        int ans = floor + num;

        cout << ans << "\n";
    }

    return 0;
}