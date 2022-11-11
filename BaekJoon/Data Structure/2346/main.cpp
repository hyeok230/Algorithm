#include <iostream>
#include <deque>

using namespace std;

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, num, index, move, push_index, push_move;
	deque<  pair<int,int> > dq;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> num;
		dq.push_back(make_pair(i + 1, num));
	}

	index = dq.front().first;
	move = dq.front().second;
	dq.pop_front();
	cout << index << " ";

	while (!dq.empty())
	{
		if (move >= 0)
		{
			for (int i = 0; i < move -1; i++)
			{
				push_index = dq.front().first;
				push_move = dq.front().second;
				dq.pop_front();
				dq.push_back(make_pair(push_index, push_move));
			}
			index = dq.front().first;
			move = dq.front().second;
			dq.pop_front();
			cout << index << " ";
		} else {
			move *= -1;
			for (int i = 0; i < move -1; i++)
			{
				push_index = dq.back().first;
				push_move = dq.back().second;
				dq.pop_back();
				dq.push_front(make_pair(push_index, push_move));
			}
			index = dq.back().first;
			move = dq.back().second;
			dq.pop_back();
			cout << index << " ";
		}
	}
}