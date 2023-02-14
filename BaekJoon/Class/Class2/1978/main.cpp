#include <iostream>
#include <cmath>
using namespace std;

int N;
int list[100];

int main()
{
    ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> N;
    int answer = N;
    for (int i = 0; i < N; i++)
    {
        cin >> list[i];
        if (list[i] == 1)
            answer--;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 2; j <= sqrt(list[i]); j++)
        {
            if (list[i] % j == 0)
            {
                answer--;
                break ;
            }
        }
    }
    cout << answer;
}