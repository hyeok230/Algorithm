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

// int m[MAX][MAX][MAX];
// int visited[MAX][MAX][MAX];
// int N, M, H;
// int x, y;
// int dx[6] = {0, -1, 1, 0, 0, 0};
// int dy[6] = {-1, 0, 0, 1, 0, 0};
// int dh[6] = {0, 0, 0, 0, 1, -1};
// int answer = 0;
int list[13];
int ans[6];
int num;
void dfs(int start, int depth) {
    if (depth == 6) {
        for (int i = 0; i < 6; i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
        return ;
    }

    for (int i = start; i < num; i++) {
        ans[depth] = list[i];
        dfs(i+1, depth+1);
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    while (1) {
        cin >> num;
        if (num == 0) break;
        int n;
        for (int i = 0; i < num; i++) {
            cin >> n;
            list[i] = n;
        }
        dfs(0, 0);
        cout << "\n";
    }


    return 0;
}