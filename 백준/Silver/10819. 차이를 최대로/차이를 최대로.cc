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
int max_n = -1;
int list[MAX];
int sum_list[MAX];
bool check[MAX];

void dfs(int pos) {
    if (pos == N) {
        int sum = 0;
        for (int i = 1; i < N; i++) {
            sum += abs(sum_list[i] - sum_list[i - 1]);
        }
        max_n = max(max_n, sum);
        return ;
    }

    for (int i = 0; i < N; i++) {
        if (check[i] == false) {
            check[i] = true;
            sum_list[pos] = list[i];
            dfs(pos + 1);
            check[i] = false;
        }
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        list[i] = num;
    }
    dfs(0);

    cout << max_n;
    return 0;
}