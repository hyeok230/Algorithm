#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <memory.h>
#include <map>
#include <algorithm>
using namespace std;

#define MAX 101

int m[MAX][MAX];
int visited[MAX][MAX];
int N, M;
int x, y;
int dx[4] = {0, -1, 1, 0};
int dy[4] = {-1, 0, 0, 1};
// memset(visited, 0, sizeof visited);
int answer = 0;
int cheese_n = 0;

void BFS() {
    queue< pair<int, int> > q;
    q.push({0, 0});
    m[0][0] = -1; 
    visited[0][0] = 1;

    while(!q.empty()) {
        int a = q.front().first;
        int b = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int newY = a + dy[i];
            int newX = b + dx[i];
            if ((newY >= 0 && newY < N) && (newX >= 0 && newX < M)) {
                if (visited[newY][newX] == 0 && m[newY][newX] <= 0) {
                    visited[newY][newX] = 1;
                    m[newY][newX] = -1;
                    q.push({newY, newX});
                }
            }
        }
    }   
}

int main() {
    ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            int n;
            cin >> n;
            m[i][j] = n;
            if (n == 1) {
                cheese_n++;
            }
        }
    }
    int first_cheese = cheese_n;

    vector<int> v;
    while (cheese_n) {
        for (int i = 0; i < N; ++i) {
            memset(visited[i], 0, sizeof(int) * M);
        }

        BFS();

    //      for (int i = 0; i < N; ++i) {
    //     for (int j = 0; j < M; ++j) {
    //         cout << m[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    // cout << "======================================\n";

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (m[i][j] == 1) {
                    for (int k = 0; k < 4; ++k) {
                        int newY = i + dy[k];
                        int newX = j + dx[k];

                        if ((newY >= 0 && newY < N) && (newX >= 0 && newX < M)) {
                            if (m[newY][newX] == -1) {
                                m[i][j] = 0;
                                cheese_n--;
                                break ;
                            }
                        }
                    }
                }
            }
        }
        v.push_back(cheese_n);
    }

    // for (int i = 0; i < N; ++i) {
    //     for (int j = 0; j < M; ++j) {
    //         cout << m[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    cout << v.size() << "\n";
    if (v.size() < 2) {
        cout << first_cheese;
    } else if (v.size() == 1) {
        cout << first_cheese;
    } else {
        cout << v[v.size() - 2];
    }
    
    return 0;
}