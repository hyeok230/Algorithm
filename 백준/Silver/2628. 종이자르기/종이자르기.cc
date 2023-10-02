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

int N, M;
vector<int> r_pq;
vector<int> c_pq;
int max_r = -1;
int max_c = -1;

int main() {
    ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> N >> M;  
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int col_row, num;
        cin >> col_row >> num;

        if (col_row == 0) {
            r_pq.push_back(num);
        } else {
            c_pq.push_back(num);
        }
    }
    r_pq.push_back(0);
    c_pq.push_back(0);
    r_pq.push_back(M);
    c_pq.push_back(N);
    sort(r_pq.begin(), r_pq.end());
    sort(c_pq.begin(), c_pq.end());
    for (int i = 1; i < c_pq.size(); i++) {
        int c_len = c_pq[i] - c_pq[i - 1];
        max_c = max(max_c, c_len);
    }
    for (int i = 1; i < r_pq.size(); i++) {
        int r_len = r_pq[i] - r_pq[i - 1];
        max_r = max(max_r, r_len);
    }
    cout << max_c * max_r;    

    return 0;
}