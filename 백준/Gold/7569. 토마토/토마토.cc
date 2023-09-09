#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <memory.h>
#include <map>
#include <algorithm>
using namespace std;

#define MAX 101

int m[MAX][MAX][MAX];
int visited[MAX][MAX][MAX];
int N, M, H;
// int x, y;
int dx[6] = {0, -1, 1, 0, 0, 0};
int dy[6] = {-1, 0, 0, 1, 0, 0};
int dh[6] = {0, 0, 0, 0, 1, -1};
int answer = 0;

void BFS() {
    queue< pair< pair<int, int>, int > > q;
    for (int k = 0; k < H; ++k) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (m[i][j][k] == 1) {
                    q.push({{i,j}, k});
                    visited[i][j][k] = 1;
                }   
            }
        }
    }

    while (!q.empty()) {
        int a = q.front().first.first;
        int b = q.front().first.second;
        int c = q.front().second;
        q.pop();

        for (int i = 0; i < 6; ++i) {
            int newY = a + dy[i];
            int newX = b + dx[i];
            int newH = c + dh[i];

            if ((newY >= 0 && newY < N) && (newX >= 0 && newX < M) && (newH >= 0 && newH < H)) {
                if (visited[newY][newX][newH] == 0 && m[newY][newX][newH] == 0) {
                    m[newY][newX][newH] = 1;
                    visited[newY][newX][newH] = visited[a][b][c] + 1;
                    q.push({{newY, newX}, newH}); 
                }
            }
        }
    }

    int max_n = -5;

    for (int k = 0; k < H; ++k) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (m[i][j][k] == 0) {
                    cout << -1;
                    return;
                }
                max_n = max(max_n, visited[i][j][k]);
            }
        }
    }
    cout << max_n - 1;
}

int main() {
    ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> M >> N >> H;

    for (int k = 0; k < H; ++k) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                int n;
                cin >> n;
                m[i][j][k] = n;
            }
        }
    }

    BFS();    
    
    return 0;
}