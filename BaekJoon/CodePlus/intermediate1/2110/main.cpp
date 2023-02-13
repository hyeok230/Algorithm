#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, C;
vector<int> v;

bool install(int n)
{
    int c = C - 1;
    int start = v[0];
    for (int i = 1; i < N; i++)
    {
        int end = v[i];
        if (end - start >= n)
        {
            c--;
            start = end;
        }
            
    }
    if (c <= 0)
        return true;
    return false;
}

int main()
{
    ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> N >> C;

    int n;
    for (int i = 0; i < N; i++)
    {
        cin >> n;
        v.push_back(n);
    }
    sort(v.begin(), v.end());

    int left = 0, right = v[N-1] - v[0], mid;
    int answer = 0;
    while (left <= right)
    {
        mid = (left + right) / 2;

        if (install(mid))
        {
            left = mid + 1;
            answer = mid;
        } else {
            right = mid - 1;
        }
    }
    cout << answer;
}