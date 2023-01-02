#include <iostream>
#include <memory.h>

#define MAX 100001
using namespace std;

int N, K;
int arr[MAX];
int result;
int count[101];

void clear_count()
{
    memset(count, 0, sizeof(count));
}

int main()
{
    ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> N >> K;

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    int tmp = 0;
    for (int i = 0; i < N; i++)
    {
        count[arr[i]]++;
        if (count[arr[i]] > K)
        {
            if (result < tmp)
                result = tmp;
            tmp = 0;
            clear_count();
        }
        tmp++;
    }
    cout << result;
}