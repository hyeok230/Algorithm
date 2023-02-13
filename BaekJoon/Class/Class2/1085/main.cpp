#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n1, n2, n3, n4;
priority_queue<int, vector<int>, greater<int> > pq;
int main()
{
    ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> n1 >> n2 >> n3 >> n4;

    pq.push(n1);
    pq.push(n2);
    pq.push(n3 - n1);
    pq.push(n4 - n2);
    
    cout << pq.top();
}