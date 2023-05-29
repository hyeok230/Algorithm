#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N;

struct cmp {
    bool operator()(pair<int, int> a, pair<int, int>b){
		if (a.first == b.first) {
            return a.second > b.second;
        } else {
            return a.first > b.first;
        }
	}
};

int main() {
    ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> N;
    
    priority_queue< pair<int, int>, vector< pair<int, int>>, cmp > q;

    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        q.push({a, b});
    }

    for (int i = 0; i < N; i++) {
        cout << q.top().first << " " << q.top().second << "\n";
        q.pop();
    }

    return 0;
}