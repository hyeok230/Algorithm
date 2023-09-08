#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <memory.h>
#include <map>
#include <algorithm>
using namespace std;

#define MAX 1024

int m[MAX][MAX];
int visited[MAX][MAX][2];
int N, M;
int x, y;
int dx[4] = {0, -1, 1, 0};
int dy[4] = {-1, 0, 0, 1};
// memset(visited, 0, sizeof visited);
int answer = 0;

void BFS() {
    queue< pair< pair<int, int>, int> > q;
    q.push({{0, 0}, 1});
    visited[0][0][1] = 1;

    while (!q.empty()) {
        int a = q.front().first.first;
        int b = q.front().first.second;
        int block = q.front().second;
        q.pop();

        if (a == N - 1 && b == M - 1) {
            cout << visited[a][b][block];
            return ;
        }

        for (int i = 0; i < 4; ++i) {
            int newY = a + dy[i];
            int newX = b + dx[i];

            if ((newY >= 0 && newY < N) && (newX >= 0 && newX < M)) {
                if (m[newY][newX] == 1 && block) {
                    q.push({{newY, newX}, block - 1});
                    visited[newY][newX][block - 1] = visited[a][b][block] + 1;
                } else if (m[newY][newX] == 0 && visited[newY][newX][block] == 0) {
                    q.push({{newY, newX}, block});
                    visited[newY][newX][block] = visited[a][b][block] + 1;
                }
            }
        }
    }

    cout << -1;
}

int main() {
    ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; ++i) {
        string str;
        cin >> str;
        for (int j = 0; j < M; ++j) {
            int n = str[j] - '0';
            m[i][j] = n;
        }
    }
    // for(int i = 0; i < N; ++i) {
    //     for (int j = 0; j < M; ++j) {
    //         cout << m[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    BFS();

    return 0;
}