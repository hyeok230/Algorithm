#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <memory.h>
#include <map>
#include <algorithm>
#include <math.h>
using namespace std;

#define MAX 101
int N;
char m[MAX][MAX];
bool visit[MAX];
bool run = false;

bool if_meet(int x, int y) {
    for (int i = x; i >= 0; i--) {
        if (m[i][y] == 'O') break;
        if (m[i][y] == 'S') return true;
    }
    for (int i = x; i < N; i++) {
        if (m[i][y] == 'O') break;
        if (m[i][y] == 'S') return true;
    }
    for (int i = y; i >= 0; i--) {
        if (m[x][i] == 'O') break;
        if (m[x][i] == 'S') return true;
    }
    for (int i = y; i < N; i++) {
        if (m[x][i] == 'O') break;
        if (m[x][i] == 'S') return true;
    }
    return false;
}

bool can_run() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (m[i][j] == 'T') {
                if (if_meet(i, j)) {
                    return false;
                }
            }
        }
    }
    return true;
}

void dfs(int idx, int cnt) {
    if (cnt == 3) {
        if (can_run()) {
            run = true;
        } 
        return ;
    }

    for (int i = idx; i < N * N; i++) {
        if (visit[i] == true) continue;
        int x = i / N;
        int y = i % N;
        if (m[x][y] == 'X') {
            visit[i] = true;
            m[x][y] = 'O';
            dfs(i, cnt + 1);
            visit[i] = false;
            m[x][y] = 'X';
        }
        
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> m[i][j];
        }
    }
    dfs(0, 0);
    if (run) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}