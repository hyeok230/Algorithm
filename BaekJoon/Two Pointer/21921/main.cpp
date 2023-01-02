#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int N, X;
int maxN;
map< int, int, greater<int> > m;
int main()
{
    ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> N >> X;
    int arr[N + 1];

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    
    int sum = 0;
    for (int i = 0; i < X; i++)
    {
        sum += arr[i];
    }
    maxN = sum;
    m[sum]++;
    for (int i = 0; i < N - X; i++)
    {
        sum -= arr[i];
        sum += arr[X + i];
        if (maxN < sum)
            maxN = sum;
        m[sum]++;
    }
    if (m.begin()->first == 0)
    {
        cout << "SAD";
        return (0);
    }
    cout << maxN << "\n";
    cout << m.begin()->second;
}