#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <memory.h>
#include <map>
#include <algorithm>
#include <math.h>
using namespace std;

#define MAX 101

int N, K;
int v[101];
int w[101];
int dp[101][100001];

int main() {
    ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> N >> K;

    for (int i = 1; i <= N; ++i) {
        cin >> w[i] >> v[i];
    }

    // for (int i = 0; i <= N; i++) {
    //     dp[i][0] = 0;
    // }
    // for (int i = 0; i <= K; ++i) {
    //     dp[0][i] = 0;
    // }

    for (int limit = 1; limit <= K; ++limit) {
        for (int item = 1; item <= N; ++item) {
            if (w[item] > limit) {
                dp[item][limit] = dp[item-1][limit];
            } else {
                dp[item][limit] = max(dp[item - 1][limit - w[item]] + v[item], dp[item-1][limit]);
            }
        }
    }

    cout << dp[N][K];
    return 0;
}