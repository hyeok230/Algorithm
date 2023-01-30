#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
#define MAX 251

int N, M;
int g[MAX][MAX];
bool check[MAX];
int cnt;

void dfs(int n)
{
    check[n] = true;
    cnt++;
    
    for (int i = 1; i <= N; i++)
    {
        if (!check[i] && g[n][i])
            dfs(i);
    } 
}

void clear_check()
{
    for (int i = 0; i < N; i++)
        check[i] = 0;
}

int main()
{
    ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> N >> M;

    int a, b;
    for (int i = 0; i < M; i++)
    {
        cin >> a >> b;
        g[a][b] = 1;
        g[b][a] = 1;
    }
    
    dfs(1);

    if (cnt == N)
    {
        cout << 0;
        return (0);
    }
    for (int i = 2; i <= N; i++)
    {
        if (check[i] != 1)
        {
            cout << i << "\n";
        }
    }
}