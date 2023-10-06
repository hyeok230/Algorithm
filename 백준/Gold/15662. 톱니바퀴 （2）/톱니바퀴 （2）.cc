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
using namespace std;

#define MAX 1001

int T, K;
deque< deque<int> > v;
int list[MAX];

int main() {
    ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> T;
    for (int i = 0; i < T; i++) {
        string str;
        cin >> str;
        deque<int> vec;
        for (int j = 0; j < str.size(); j++) {
            vec.push_back(str[j] - '0');
        }
        v.push_back(vec);
    }
    cin >> K;
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < T; j++) list[j] = 0;
        int a, b;
        cin >> a >> b;
        list[a - 1] = b;
        for (int k = a - 1; k < T - 1; k++) {
            if (v[k][2] != v[k+1][6]) {
                list[k+1] = list[k] * -1;
            }
        }
        for (int k = a - 1; k >= 1; k--) {
            if (v[k][6] != v[k-1][2]) {
                list[k-1] = list[k] * -1;
            }
         }
        for (int k = 0; k < T; k++) {
            int temp;
            if (list[k] == 1) {
                temp = v[k].back();
                v[k].pop_back();
                v[k].push_front(temp);
            } else if (list[k] == -1) {
                temp = v[k].front();
                v[k].pop_front();
                v[k].push_back(temp);
            }
        }
    }
    

    int cnt = 0;
    for (int i = 0; i < T; i++) {
        if (v[i][0] == 1) cnt++;
    }
    cout << cnt;

    return 0;
}