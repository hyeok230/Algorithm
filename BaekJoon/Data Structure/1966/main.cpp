#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	int n, N, M, num, cnt = 0;
	
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> N >> M;
		cnt = 0;
		queue< pair<int, int> > q;
		priority_queue<int> pq;

		for (int j = 0; j < N; j++)
		{
			cin >> num;
			q.push(make_pair(num, j));
			pq.push(num);
		}

		while (!q.empty())
		{
			int value = q.front().first;
			int index = q.front().second;
			q.pop();
			if (pq.top() == value)
			{
				pq.pop();
				cnt++;
				if (index == M)
				{
					cout << cnt << "\n";
					break ;
				}
			} else {
				q.push(make_pair(value, index));
			}
		}
	}
}