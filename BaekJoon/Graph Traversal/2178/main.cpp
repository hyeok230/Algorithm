#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;
#define MAX 101

int N, M;
int map[MAX][MAX];
queue< pair<int, int> > q;
int dist[MAX][MAX];

void bfs(int y, int x)
{
    q.push(make_pair(y, x));
    dist[y][x]++;
    
    while (!q.empty())
    {
        int u = q.front().first;
        int v = q.front().second;
        q.pop();

        if (u == N - 1 && v == M -1)
            break;
        
        if (u - 1 >= 0 && v >= 0 && u - 1 < N && v < M && map[u - 1][v] && !dist[u - 1][v])
        {
            q.push(make_pair(u - 1, v));
            dist[u - 1][v] = dist[u][v] + 1;
        } 
        if (u >= 0 && v + 1 >= 0 && u < N && v + 1 < M && map[u][v + 1] && !dist[u][v + 1]) {
            q.push(make_pair(u, v + 1));
            dist[u][v + 1] = dist[u][v] + 1;
        }
        if (u + 1 >= 0 && v >= 0 && u + 1 < N && v < M && map[u + 1][v] && !dist[u + 1][v]) {
            q.push(make_pair(u + 1, v));
            dist[u + 1][v] = dist[u][v] + 1;
        }
        if (u >= 0 && v - 1 >= 0 && u < N && v - 1 < M && map[u][v - 1] && !dist[u][v - 1]) {
            q.push(make_pair(u, v - 1));
            dist[u][v - 1] = dist[u][v] + 1;
        }
    }
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        string str;

        cin >> str;

        for (int j = 0; j < M; j++)
        {
            map[i][j] = str[j] - '0';
        }
    }

    bfs(0, 0);

   cout << dist[N - 1][M - 1];
}