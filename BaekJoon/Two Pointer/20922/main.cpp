#include <iostream>
#include <memory.h>
#include <algorithm>

#define MAX 200001
using namespace std;

int N, K;
int arr[MAX];
int result;
int countN[100001];

int main()
{
    ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> N >> K;

    int start = 0;
    int result = 0;

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        countN[arr[i]]++;
        while (countN[arr[i]] > K)
        {
            countN[arr[start++]]--;
        }
        result = max(result, i - start + 1);
    }
    cout << result;
    return 0;
}