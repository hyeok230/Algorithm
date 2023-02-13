#include <iostream>
#include <string>

using namespace std;

int N, k;

int get_length(int n)
{
    int length = 0;

    for (int start = 1, len = 1; start <= n; start *= 10, len++)
    {
        int end = start * 10 - 1;
        if (end > n)
            end = n;
        length += ((end - start) + 1) * len;
    }
    return (length);
}

int main()
{
    ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> N >> k;

    if (get_length(N) < k)
    {
        cout << -1;
        return 0;
    }

    int left = 1, right = N, mid, pos;
    while (left <= right)
    {
        mid = (left + right) / 2;

        if (get_length(mid) < k)
        {
            left = mid + 1;
        } else {
            pos = mid;
            right = mid - 1;
        }
    }

    int len = get_length(pos);
    string str = to_string(pos);
    char answer = str[str.size() - 1 - (len - k)];
    cout << answer;
}