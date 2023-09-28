#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <memory.h>
#include <map>
#include <algorithm>
using namespace std;

#define MAX 1001

int m[MAX][MAX];
// int visited[MAX][MAX][MAX];
// int N, M, H;
// int x, y;
// int dx[6] = {0, -1, 1, 0, 0, 0};
// int dy[6] = {-1, 0, 0, 1, 0, 0};
// int dh[6] = {0, 0, 0, 0, 1, -1};
// int answer = 0;

int main() {
    ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
    int n;
    cin >> n;
    int num = n * n;
    int find_num;
    cin >> find_num;

    int a1 = 0;
    int b1 = 0;
    int a2 = n - 1;
    int b2 = 0;
    int a3 = n - 1;
    int b3 = n - 1;
    int a4 = 0;
    int b4 = n - 1;   

    while (1) {
        if (num == 1) {
            m[a1][b1] = 1;
            break;
        }
        for (int i = a1; i < a2; i++) {
            m[i][b1] = num;
            num--;
        }
        for (int i = b2; i < b3; i++) {
            m[a2][i] = num;
            num--;
        }
        for (int i = a3; i > a4; i--) {
            m[i][b3] = num;
            num--;
        }
        for (int i = b4; i > b1; i--) {
            m[a4][i] = num;
            num--;
        }
        a1++;
        b1++;
        a2--;
        b2++;
        a3--;
        b3--;
        a4++;
        b4--;
    }

    int x, y;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << m[i][j] << " ";
            if (m[i][j] == find_num) {
                x = i + 1;
                y = j + 1;
            }
        }
        cout << "\n";
    }
    cout << x << " " << y;
    return 0;
}