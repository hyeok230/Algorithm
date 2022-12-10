#include <iostream>
#include <algorithm>

using namespace std;
#define MAX 5001

int N;
int dp[MAX] = {-1, -1, -1, 1, -1, 1,};

int dynamic(int N)
{
    if (dp[N] != 0)
        return (dp[N]);

    if (dynamic(N -3) == -1 && dynamic(N - 5) == -1)
    {
        dp[N] = -1;
        return (dp[N]);
    }

    if (dynamic(N - 3) != -1 && dynamic(N - 5) != -1)
    {
        int num = min(dynamic(N - 3), dynamic(N - 5));
        dp[N] = num + 1;
        return (dp[N]);
    }
    if (dynamic(N - 3) != -1)
    {
        dp[N] = dynamic(N - 3) + 1;
        return (dp[N]);
    }
        
    if (dynamic(N - 5) != -1)
    {
        dp[N] = dynamic(N - 5) + 1;
        return (dp[N]);
    } 
    
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> N;

    cout << dynamic(N);

}