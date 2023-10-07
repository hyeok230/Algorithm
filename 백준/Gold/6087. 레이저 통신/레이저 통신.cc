#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <memory.h>
#include <map>
#include <algorithm>
#include <math.h>
#include <deque>
#include <climits>
using namespace std;

#define MAX 101
char m[MAX][MAX];
bool visit[MAX][MAX];
int W, H;
vector< pair<int, int> > v;
int s_y, s_x, e_y, e_x;
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

int bfs(int s_y, int s_x) {
    queue< pair < pair<int, int>, int> > q;
    q.push({{s_y, s_x}, -1});
    visit[s_y][s_x] = 1;

    while (!q.empty()) {
        int y = q.front().first.first;
        int x = q.front().first.second;
        int cnt = q.front().second;
        q.pop();

        if (y == e_y && x == e_x) return cnt;

        for (int i = 0; i < 4; i++) {
            int new_y = y;
            int new_x = x;
            while (true) {
                new_y += dy[i];
                new_x += dx[i];
                if (new_y < 0 || new_x < 0 || new_y >= H || new_x >= W) break;
                if (m[new_y][new_x] == '*') break;
                if (!visit[new_y][new_x]) {
                    q.push({{new_y, new_x}, cnt + 1});
                    visit[new_y][new_x] = 1;
                }
            }
        }
    }
}


int main() {
    ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> W >> H;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> m[i][j];
            if (m[i][j] == 'C') {
                v.push_back({i, j});
            }
        }
    }

    s_y = v[0].first;
    s_x = v[0].second;
    e_y = v[1].first;
    e_x = v[1].second;

    int cnt = bfs(s_y, s_x);
    cout << cnt;
    return 0;
}