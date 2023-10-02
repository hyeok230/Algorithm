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

#define MAX 1001

// int m[MAX][MAX];
// int visited[MAX][MAX];
// int N, M, H;
// int x, y;
// int dx[4] = {0, -1, 1, 0};
// int dy[4] = {-1, 0, 0, 1};
// int dx[6] = {0, -1, 1, 0, 0, 0};
// int dy[6] = {-1, 0, 0, 1, 0, 0};
// int dh[6] = {0, 0, 0, 0, 1, -1};
// int answer = 0;

int N;
int list[MAX];
bool visit[MAX];

void dfs(int pos) {
    if (pos == N) {
        for (int i = 0; i < N; i++) {
            cout << list[i] << " ";
        }
        cout << "\n";
    }

    for (int i = 0; i < N; i++) {
        if (visit[i] == false) {
            visit[i] = true;
            list[pos] = i + 1;
            dfs(pos + 1);
            visit[i] = false;
        }
    }

}

int main() {
    ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> N;  

    dfs(0);  

    return 0;
}