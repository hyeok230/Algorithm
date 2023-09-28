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

int m[MAX][MAX];
// int visited[MAX][MAX][MAX];
// int N, M, H;
// int x, y;
// int dx[6] = {0, -1, 1, 0, 0, 0};
// int dy[6] = {-1, 0, 0, 1, 0, 0};
// int dh[6] = {0, 0, 0, 0, 1, -1};
// int answer = 0;

bool if_bingo() {
    int count = 0;

    for (int i = 0; i < 5; i++) {
        bool col = true;
        bool row = true;
        for (int j = 0; j < 5; j++) {
            if (m[i][j] != 0) row = false;
            if (m[j][i] != 0) col = false;
        }
        if (col) count++;
        if (row) count++;
    }

    if (!m[0][0] && !m[1][1] && !m[2][2] && !m[3][3] && !m[4][4]) count++;
    if (!m[0][4] && !m[1][3] && !m[2][2] && !m[3][1] && !m[4][0]) count++;

    if (count >= 3) return true;
    return false;
}

int main() {
    ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int ans;    
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> m[i][j];
        }
    }

    int list[25];
    for (int i = 0; i < 25; i++) {
        cin >> list[i];
    }

    for (int i = 0; i < 25; i++) {
        for (int x = 0; x < 5; x++) {
            for (int y = 0; y < 5; y++) {
                if (m[x][y] == list[i]) {
                    m[x][y] = 0;
                }
            }
        }

        if (if_bingo()) {
            ans = i + 1;
            cout << ans;
            break;
        }
    }


    return 0;
}