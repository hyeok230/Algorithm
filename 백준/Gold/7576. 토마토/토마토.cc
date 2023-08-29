#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;
#define MAX 1001

int N, M;
int MAP[MAX][MAX];
bool visited[MAX];
int answer = 0;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

queue< pair<int, int> > q;


int main() {
    ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> M >> N;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int x;
            cin >> x;
            MAP[i][j] = x;
            if (x == 1) {
                q.push(make_pair(i, j));
            }
        }
    }


    while (!q.empty()) {
        int x, y;
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int newX, newY;
            newX = x + dx[i];
            newY = y + dy[i];
            if ((newX >= 0 && newX < N) && (newY >= 0 && newY < M) && MAP[newX][newY] == 0) {
                MAP[newX][newY] = MAP[x][y] + 1;
                q.push(make_pair(newX, newY));
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (MAP[i][j] == 0) {
                cout << -1;
                return 0;
            }
            if (answer < MAP[i][j]) {
                answer = MAP[i][j];
            }
        }
    }
    cout << answer - 1;
    return 0;
}