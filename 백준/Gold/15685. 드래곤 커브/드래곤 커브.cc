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


// int visited[MAX][MAX];
// int N, M, H;
// int x, y;
// int dx[6] = {0, -1, 1, 0, 0, 0};
// int dy[6] = {-1, 0, 0, 1, 0, 0};
// int dh[6] = {0, 0, 0, 0, 1, -1};
// int answer = 0;

int m[MAX][MAX];
int N;
int x, y, d, g, ans;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
vector<int> v;

void count_squre() {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            if (m[i][j] == 1 && m[i+1][j] == 1 && m[i][j+1] == 1 && m[i+1][j+1] == 1) {
                ans++;
            }
        }
    }
}

void dragon_curve() {
    int size = v.size();
    for (int i = size - 1; i >= 0; --i) {
        int dir = (v[i] + 1) % 4; 
        x += dx[dir];
        y += dy[dir];
        m[x][y] = 1;
        v.push_back(dir);
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> N;

    while (N--) {
        v.clear();
        cin >> x >> y >> d >> g;

        m[x][y] = 1;
        x += dx[d];
        y += dy[d];
        m[x][y] = 1;
        v.push_back(d);
        
        while (g--) {
            dragon_curve();
        }
    }
    count_squre();
    cout << ans;

    return 0;
}