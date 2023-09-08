#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <queue>
#include <iostream>

using namespace std;
#define MAX 101
int m[MAX][MAX];
int visited[MAX][MAX];

int BFS(int a, int n) {
    int count = 1;
    
    queue<int> q;
    q.push(a);
    
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        
        for (int i = 1; i <= n; i++) {
            if (m[x][i] == 1 && visited[x][i] == 0) {
                visited[x][i] = 1;
                visited[i][x] = 1;
                q.push(i);
                count++;
            }
        }   
    }
    return count;
}

void reset_visit(int n) {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            visited[i][j] = 0;
            visited[j][i] = 0;  
        }
    }
}

int solution(int n, vector<vector<int>> wires) {
    int answer = MAX;
    
    for (int i = 0; i < wires.size(); ++i) {
        int a = wires[i][0];
        int b = wires[i][1];
        m[a][b] = 1;
        m[b][a] = 1;
    }
    // for(int i = 1; i <= n; ++i) {
    //     for(int j = 1; j <= n; ++j) {
    //         cout << m[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    
    for (int i = 0; i < wires.size(); ++i) {
        int a = wires[i][0];
        int b = wires[i][1];
        m[a][b] = 0;
        m[b][a] = 0;
        reset_visit(n);
        int n1 = BFS(a, n);
        reset_visit(n);
        int n2 = BFS(b, n);
        answer = min(answer, abs(n1-n2));
        m[a][b] = 1;
        m[b][a] = 1;
    }
    
    return answer;
}