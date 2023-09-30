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

int m[MAX][MAX];
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
int min_n = 9999999;
bool check[MAX];

void dfs(int x, int pos) {
    if (x == N/2) {
        int start, link;
        start = 0;
        link = 0;
        
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (check[i] == true && check[j] == true) start += m[i][j];
                if (check[i] == false && check[j] == false) link += m[i][j];
            }
        }
        min_n = min(min_n, abs(start - link));    
        return;
    }
    
    for (int i = pos; i <= N; i++) {
        check[i] = true;
        dfs(x + 1, i + 1);
        check[i] = false;
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int num;
            cin >> num;
            m[i][j] = num;
        }
    }
    dfs(0, 1);

    cout << min_n;
    return 0;
}