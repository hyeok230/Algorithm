#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;
#define MAX 1001

int T, N, M, K;
int MAP[MAX][MAX];
bool visited[MAX];
int number = 0;
priority_queue<int, vector<int>, greater<int>> pq;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};


void BFS(int x, int y) {
    number++;
    queue< pair<int, int> > q;
    q.push(make_pair(x, y));
    MAP[x][y] = 0;

    while (!q.empty()) {
        int a, b;
        a = q.front().first;
        b = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int newX, newY;
            newX = a + dx[i];
            newY = b + dy[i];
            if ((newX >= 0 && newX < N) && (newY >= 0 && newY < M) && MAP[newX][newY] == 1) {
                q.push(make_pair(newX, newY));
                MAP[newX][newY] = 0;
            }
        }
    }
    
}

int main() {
    ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> T;
    vector<int> v;
    for (int k = 0; k < T; k++) {
        cin >> N >> M >> K;

        for (int i = 0; i < K; i++) {
            int x, y;
            cin >> x >> y;
            MAP[x][y] = 1;
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (MAP[i][j] == 1) {
                    BFS(i, j);
                }
            }
        }
        v.push_back(number);
        number = 0;
    }

    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << "\n";
    }
    return 0;
}