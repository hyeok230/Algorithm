#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int list[1000000];

long long int get_length(long long int n)
{
    long long int len = 0;
    for (int i = 0; i < N; i++)
    {
        if (list[i] > n)
            len += (list[i] - n);
    }
    return (len);
}

int main()
{
    ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> N >> M;
    int maxn = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> list[i];
        maxn = max(maxn, list[i]);
    }
    int left = 0, right = maxn, mid;
    int answer;
    while (left <= right)
    {
        mid = (left + right) / 2;

        if (get_length(mid) < M)
        {
            right = mid - 1;
        } else {
            answer = mid;
            left = mid + 1;
        }
    }
    cout << answer;
}