#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
using namespace std;

#define MAX 1024

int m[MAX][MAX];
int visited[MAX][MAX];
int N, M;
int x, y;
// int dx[4] = {0, -1, 0, 1};
// int dy[4] = {1, 0, -1, 0};
int answer = 0;

void DFS() {
    stack< pair<int, int> > s;

    for (int i = 1; i <= N; ++i) {
        if (m[x][i] == 1) {
            s.push(make_pair(x,i));
            visited[x][i] = 1;
        }
    }
    while(!s.empty()) {
        int a = s.top().first;
        int b = s.top().second;
        s.pop();
        for (int i = 1; i <= N; i++) {
            if (m[b][i] != 0 && !visited[b][i]) {
                visited[b][i] = 1;
                m[b][i] = m[a][b] + 1;
                if (i == y) {
                    cout << m[b][i];
                    return ;
                } else {
                    s.push(make_pair(b, i));
                }
            }
        }
    }

    cout << -1;
    return ;
}

int main() {
    ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> N;
    cin >> x >> y;
    cin >> M;

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        m[a][b] = 1;
        m[b][a] = 1;
    }

    DFS();

    return 0;
}