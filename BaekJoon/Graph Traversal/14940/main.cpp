#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;
#define MAX 1001

int n, m;
int map[MAX][MAX];
int check[MAX][MAX];
queue< pair<int, int> > q;
int u, v;

void bfs(int i, int j)
{
    q.push(make_pair(i, j));
    while (!q.empty())
    {
        int a, b;
        a = q.front().first;
        b = q.front().second;
        q.pop();
        
        if (a - 1 >= 0 && b >= 0 && a - 1 < n && b < m && map[a - 1][b] == 1 && !check[a - 1][b])
        {
            check[a - 1][b] = check[a][b] + 1;
            q.push(make_pair(a - 1, b));
        }
        if (a >= 0 && b + 1 >= 0 && a < n && b + 1 < m && map[a][b + 1] == 1 && !check[a][b + 1])
        {
            check[a][b + 1] = check[a][b] + 1;
            q.push(make_pair(a, b + 1));
        }
        if (a + 1 >= 0 && b >= 0 && a + 1 < n && b < m && map[a + 1][b] == 1 && !check[a + 1][b])
        {
            check[a + 1][b] = check[a][b] + 1;
            q.push(make_pair(a + 1, b));
        }
        if (a >= 0 && b - 1 >= 0 && a < n && b - 1 < m && map[a][b - 1] == 1 && !check[a][b - 1])
        {
            check[a][b - 1] = check[a][b] + 1;
            q.push(make_pair(a, b - 1));
        }
    }
}


int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> n >> m;

    int num;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
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

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] == 1 && !check[i][j])
                check[i][j] = -1;
        }
    }


    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << check[i][j] << " ";
        }
        cout << "\n";
    }
}