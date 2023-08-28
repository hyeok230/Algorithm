#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
#define MAX 1001

int map[MAX][MAX];
bool check[MAX];
bool check2[MAX];
int N, M, V;
queue<int> q;

void dfs(int n)
{
    check[n] = true;
    cout << n << " ";
    
    for (int i = 1; i <= N; i++)
    {
        if (!check[i] && map[n][i])
            dfs(i);
    }     
}

void bfs(int n)
{
    q.push(n);
    check2[n] = true;
    cout << n << " ";
    while(!q.empty())
    {
        int k = q.front();
        q.pop();

        for (int i = 1; i <= N; i++)
        {
            if (!check2[i] && map[k][i])
            {
                q.push(i);
                check2[i] = true;
                cout << i << " ";
            }
        }
    }
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    
    cin >> N >> M >> V;

    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        map[u][v] = 1;
        map[v][u] = 1;
    }

    dfs(V);
    cout << "\n";
    bfs(V);
}