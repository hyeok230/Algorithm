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
    
    set<string> s1;
    set<string> s2;
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        s1.insert(str);
    }
    for (int i = 0; i < M; i++) {
        string str;
        cin >> str;
        s2.insert(str);
    }
    vector<string> ans;
    for (auto str: s1) {
        if (s1.count(str) && s2.count(str)) {
            ans.push_back(str);
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << "\n";
    }

    return 0;
}