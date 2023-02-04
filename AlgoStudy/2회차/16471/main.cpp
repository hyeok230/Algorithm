#include <iostream>
#include <queue>
#include <functional>

using namespace std;

int N;
priority_queue<int> qa;
priority_queue<int> qb;

int main()
{
    ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> N;
    int n;
    for(int i = 0; i < N; i++)
    {
        cin >> n;
        qa.push(n);
    }
    for(int i = 0; i < N; i++)
    {
        cin >> n;
        qb.push(n);
    }
    int point = 0;
    while (!qa.empty())
    {
        if (qa.top() < qb.top())
        {
            point++;
            qb.pop();
        }
        qa.pop();
    }

    if (point >= (N + 1) / 2)
        cout << "YES";
    else
        cout << "NO";
}