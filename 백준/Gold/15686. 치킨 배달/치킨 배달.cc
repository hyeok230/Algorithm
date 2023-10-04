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

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
int m[MAX][MAX];
int N, M, v_size;
vector< pair<int, int> > house, chicken, v;
bool visit[13];
int min_chicken = 9999;

void dfs(int idx, int cnt) {
    if (cnt == M) {
        int sum = 0;
        for (int i = 0; i < house.size(); i++) {
            int x = house[i].first;
            int y = house[i].second;
            int distance = 9999;

            for (int j = 0; j < v.size(); j++) {
                int a = v[j].first;
                int b = v[j].second;
                distance = min(distance, abs(x - a) + abs(y - b));
            }
            sum += distance;
        }        

        min_chicken = min(min_chicken, sum);
        return ;
    }

    for (int i = idx; i < v_size; i++) {
        if (visit[i] == true) continue;
        visit[i]= true;
        v.push_back(chicken[i]);
        dfs(i, cnt + 1);
        v.pop_back();
        visit[i] = false;
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int n;
            cin >> n;
            m[i][j] = n;
            if (m[i][j] == 1) house.push_back({i, j});
            if (m[i][j] == 2) chicken.push_back({i, j});
        }
    }
    v_size = chicken.size();
    dfs(0, 0);
    cout << min_chicken;
    return 0;
}