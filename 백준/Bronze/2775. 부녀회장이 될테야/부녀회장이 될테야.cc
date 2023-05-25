#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int T;

int main() {
    ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> T;
    
    for (int idx = 0; idx < T; idx++) {
        int k, n;
        cin >> k >> n;

        vector< vector<int> > v(k + 1, vector<int>(n + 1));    
        for (int j = 0; j <= k; j++) {
             for (int i = 1; i <= n; i++) {
                if (i == 1) {
                    v[j][i] = 1;
                } else {
                    if (j == 0) {
                        v[j][i] = i;
                    } else {
                        for (int p = 1; p <= i; p++) {
                            v[j][i] += v[j - 1][p];
                        }
                    }
                }
             }
        }
        cout << v[k][n] << "\n";
    }

    
    return 0;
}