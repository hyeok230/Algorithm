#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

#define MAX 21

int m[MAX][MAX];
int tmp[MAX][MAX];
int N, M;
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};
int answer = 0;

void mapCopy(int a[MAX][MAX], int b[MAX][MAX]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            a[i][j] = b[i][j];
        }
    }
}

void BFS() {
    int new_m[MAX][MAX];
    queue< pair<int, int> > q;

    mapCopy(new_m, tmp);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (new_m[i][j] == 2) {
                q.push(make_pair(i, j));
            }
        }
    }

    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int new_y = y + dy[i];
            int new_x = x + dx[i];

            if ((new_y >= 0 && new_y < N) && (new_x >= 0 && new_x < M)) {
                if (new_m[new_y][new_x] == 0) {
                    new_m[new_y][new_x] = 2;
                    q.push(make_pair(new_y, new_x));
                }
            }
        }
    }

    int count = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (new_m[i][j] == 0) {
                count++;
            }
        }
    }
    answer = max(count, answer);
}

void wall(int cnt) {
    if (cnt == 3) {
        BFS();
        return ;
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (tmp[i][j] == 0) {
                tmp[i][j] = 1;
                wall(cnt + 1);
                tmp[i][j] = 0;
            }
        }
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            int x;
            cin >> x;
            m[i][j] = x;
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (m[i][j] == 0) {
                mapCopy(tmp, m);
                tmp[i][j] = 1;
                wall(1);
                tmp[i][j] = 0;
            }
                 
        }
    }

    cout << answer;

    return 0;
}