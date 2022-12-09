#include <iostream>

using namespace std;
#define MAX 31


int T, N, M;
int dp[MAX][MAX] = {0,};

int combination(int n, int r)
{
    if (dp[n][r] != 0)
        return (dp[n][r]);
    
    if (n == r || r == 0) {
        dp[n][r] = 1;
        return (dp[n][r]);
    }
    else {
        dp[n][r] = combination(n - 1, r - 1) + combination(n - 1, r);
        return (dp[n][r]);
    }
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> N >> M;
        cout << combination(M, N) << "\n";
    }

}