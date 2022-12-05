#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;
#define MAX 1001

int N, M;
int map[MAX][MAX];
int dist[MAX][MAX];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int u, v;
queue< pair<int, int> > q;

void bfs(int a, int b)
{
    q.push(make_pair(a, b));
    
    while (!q.empty())
    {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();

        for (int k = 0; k < 4; k++)
        {
            int n = i + dy[k];
            int m = j + dx[k];
            if (n >= 0 && m >= 0 && n < N && m < M && map[n][m] == 1 && !dist[n][m])
            {
                dist[n][m] = dist[i][j] + 1;
                q.push(make_pair(n, m));
            }
        }
    }

}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> N >> M;

    int num;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> num;

            if (num == 2)
            {
                u = i;
                v = j;
            }
            map[i][j] = num;
        }
    }

    bfs(u, v);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (map[i][j] == 1 && !dist[i][j])
            {
                dist[i][j] = -1;
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
}