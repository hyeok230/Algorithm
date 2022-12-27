#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
#define MAX 1000001

int N, M;
int A[MAX];
int B[MAX];

int main()
{
    ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    for (int i = 0; i < M; i++)
    {
        cin >> B[i];
    }

    int i = 0;
    int j = 0;
    while (i < N && j < M) {
        if (A[i] <= B[j])
        {
            cout << A[i] << " ";
            i++;
        } else if (A[i] > B[j])
        {
            cout << B[j] << " ";
            j++;
        }
    }

    while (i < N)
    {
        cout << A[i] << " ";
        i++;
    }
    while (j < M)
    {
        cout << B[j] << " ";
        j++;
    }
}