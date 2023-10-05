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

#define MAX 10001
int parent[MAX];
int V, E;
int ans = 0;
vector< pair <int, pair<int, int> > > v;

int findParent(int x) {
    if (parent[x] == x) return x;
    else return parent[x] = findParent(parent[x]);
}

bool sameParent(int a, int b) {
    a = findParent(a);
    b = findParent(b);

    if (a == b) return true;
    return false;
}

void unionVertex(int a, int b) {
    a = findParent(a);
    b = findParent(b);
    parent[b] = a;
}

void MST() {
    for (int i = 0; i < v.size(); i++) {
        int a = v[i].second.first;
        int b = v[i].second.second;
        if (sameParent(a, b)) {
            continue;
        } else {
            unionVertex(a, b);
            ans += v[i].first;
        }
    }

}

int main() {
    ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> V >> E;

    for (int i = 0; i < E; i++) {
        int A, B, C;
        cin >> A >> B >> C;
        v.push_back({C, {A, B}});
    }   
    sort(v.begin(), v.end());   

    for (int i = 1; i <= V; i++) {
        parent[i] = i;
    }

    MST();
    cout << ans;
    return 0;
}