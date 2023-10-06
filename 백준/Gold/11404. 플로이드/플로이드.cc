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
using namespace std;

#define MAX 101
int N, M;
int m[MAX][MAX];

int main() {
    ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i == j) {
                m[i][j] = 0;
            } else {
                m[i][j] = 9999999;
            }
        }
    }
    cin >> M;
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (m[a][b] != 0 && m[a][b] > c) {
            m[a][b] = c;
        } else if (m[a][b] == 0) {
            m[a][b] = c;
        }
    }
    

    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (m[i][j] > m[i][k] + m[k][j]) {
                    m[i][j] = m[i][k] + m[k][j];
                }
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (m[i][j] == 9999999) {
                m[i][j] = 0;
            }   
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cout << m[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}