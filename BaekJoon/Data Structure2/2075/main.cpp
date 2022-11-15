#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	int num;
	priority_queue<int, vector<int>, greater<int> > pq;
	cin >> N;

	for (int i = 0; i < N * N; i++)
	{
		cin >> num;

		if (pq.size() < N)
		{
			pq.push(num);
		} else {
			if (pq.top() < num)
			{
				pq.pop();
				pq.push(num);
			}
		}
	}
	cout << pq.top();
}