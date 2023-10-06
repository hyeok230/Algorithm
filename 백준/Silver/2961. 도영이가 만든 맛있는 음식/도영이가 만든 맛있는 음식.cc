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

#define MAX 11

int N;
int min_diff = 99999;
vector< pair<int, int> > v;
int M, v_size;
bool visit[MAX];
long sinmat;
long ssnmat;

void dfs(int idx, int cnt) {
    if (cnt == M) {
        min_diff = min(min_diff, (int)abs(sinmat - ssnmat));
        return ;
    }

    for (int i = idx; i < v_size; i++) {
        if (visit[i] == true) continue;
        visit[i] = true;
        sinmat *= (long)v[i].first;
        ssnmat += (long)v[i].second;
        dfs(idx + 1, cnt + 1);
        sinmat /= (long)v[i].first;
        ssnmat -= (long)v[i].second;
        visit[i] = false;
    }

}

int main() {
    ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {
        int S, B;
        cin >> S >> B;
        v.push_back({S, B});
    }
    v_size = v.size();
    for (int i = 1; i <= v_size; i++) {
        M = i;
        sinmat = 1;
        ssnmat = 0;
        dfs(0, 0);
    }
    cout << min_diff;
    return 0;
}