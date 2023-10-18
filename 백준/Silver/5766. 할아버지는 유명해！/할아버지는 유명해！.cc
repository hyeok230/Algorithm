#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <memory.h>
#include <map>
#include <algorithm>
#include <math.h>
#include <deque>
#include <climits>
#include <unordered_map>
#include <set>
using namespace std;

#define MAX 101

int main() {
    ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
    int N, M;
    while (1) {
        cin >> N >> M;  
        if (N == 0 && M == 0) break;
        map<int, int> m;
        for (int i = 0; i < N; i++) {
            int n;
            for (int j = 0; j < M; j++) {
                cin >> n;
                m[n]++;
            }
        }
        set<int, greater<int>> s;
        for (auto it = m.begin(); it != m.end(); it++) {
            s.insert(it->second);
        }
        auto it = ++s.begin();
        int second = *it;
        for (auto iter = m.begin(); iter != m.end(); iter++) {
            if (second == iter->second) {
                cout << iter->first << " ";
            }
        }
        cout << "\n";
    } 
    return 0;
}