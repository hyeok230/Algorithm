#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

unsigned int K, N;
unsigned int list[10000];
unsigned int ans = 0;

int main()
{
    ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> K >> N;

    unsigned int maxn = 0;
    for (int i = 0; i < K; i++)
    {
        cin >> list[i];
        maxn = max(list[i], maxn);
    }
    unsigned int left = 1, right = maxn, mid;
    while (left <= right)
    {
        mid = (left + right) / 2;

        int n = 0;
        for (int i = 0; i < K; i++)
        {
            n += list[i] / mid;
        }

        if (n >= N)
        {
            ans = max(ans, mid);
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    cout << ans;
}