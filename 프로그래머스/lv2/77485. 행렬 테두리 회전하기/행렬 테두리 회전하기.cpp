#include <string>
#include <vector>
#include <iostream>
#include <climits>
#define MAX 101
using namespace std;
int m[MAX][MAX];

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            m[i][j] = i * columns + (j + 1);
        }
    }
    
    for (int k = 0; k < queries.size(); ++k) {
        int y = queries[k][0] - 1;
        int x = queries[k][1] - 1;
        int yy = queries[k][2] - 1;
        int xx = queries[k][3] - 1;
        int min_n = m[y][x];
        int tmp = m[y][x];
        for (int i = y; i < yy; ++i) {
            m[i][x] = m[i + 1][x];
            min_n = min(min_n, m[i][x]);
        }
        for (int i = x; i < xx; ++i) {
            m[yy][i] = m[yy][i + 1];
            min_n = min(min_n, m[yy][i]);
        }
        for (int i = yy; i > y; --i) {
            m[i][xx] = m[i - 1][xx];
            min_n = min(min_n, m[i][xx]);
        }
        for (int i = xx; i > x; --i) {
            m[y][i] = m[y][i - 1];
            min_n = min(min_n, m[y][i]);
        }
        m[y][x + 1] = tmp;
        answer.push_back(min_n);
    }
    
    return answer;
}