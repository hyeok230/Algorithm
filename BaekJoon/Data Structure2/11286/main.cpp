#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, num;
	priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > pq;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> num;

		if (num == 0)
		{
			if (pq.empty())
			{
				cout << "0\n"; 
			} else {
				cout << pq.top().second << "\n";
				pq.pop();
			}
		} else {
			if (num < 0)
			{
				pq.push(make_pair(num * -1, num));
			} else {
				pq.push(make_pair(num, num));
			}
		}
	}
}