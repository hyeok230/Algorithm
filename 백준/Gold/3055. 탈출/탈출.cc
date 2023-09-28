#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <memory.h>
#include <map>
#include <algorithm>
using namespace std;

#define MAX 1001

char m[MAX][MAX];
int visited[MAX][MAX];
// int N, M, H;
// int x, y;
int dx[4] = {0, -1, 1, 0};
int dy[4] = {-1, 0, 0, 1};
// int dx[6] = {0, -1, 1, 0, 0, 0};
// int dy[6] = {-1, 0, 0, 1, 0, 0};
// int dh[6] = {0, 0, 0, 0, 1, -1};
// int answer = 0;
queue< pair< pair<int, int>, char> > q;
int R, C;
int start_y, start_x, end_y, end_x;

int main() {
    ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < C; j++) {
            m[i][j] = str[j];
            if (m[i][j] == 'S') {
                start_y = i;
                start_x = j;
            } else if (m[i][j] == 'D') {
                end_y = i;
                end_x = j;
            } else if (m[i][j] == '*') {
                q.push({{i, j}, '*'});
            }
        }
    }

    q.push({{start_y, start_x}, 'S'});
    visited[start_y][start_x] = 1;
    
    while(!q.empty()) {
        int y = q.front().first.first;
        int x = q.front().first.second;
        char z = q.front().second;
        q.pop();
        if (y == end_y && x == end_x) break;

        for (int i = 0; i < 4; i++) {
            int new_y = y + dy[i];
            int new_x = x + dx[i];

            if ((new_y >= 0 && new_y < R) && (new_x >= 0 && new_x < C)) {
                if (z == '*') {
                    if (m[new_y][new_x] == '.' || m[new_y][new_x] == 'S') {
                        m[new_y][new_x] = '*';
                        q.push({{new_y, new_x}, '*'});
                    }
                } else {
                    if (m[new_y][new_x] == '.' || m[new_y][new_x] == 'D') {
                        if (!visited[new_y][new_x]) {
                            visited[new_y][new_x] = visited[y][x] + 1;
                            q.push({{new_y, new_x}, 'S'});
                        }
    
                    }
                }
            }

            
        }
    }
    if (visited[end_y][end_x]) {
        cout << visited[end_y][end_x] - 1;
    } else {
        cout << "KAKTUS";
    }
    return 0;
}