#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define MAX 100001

int N;
int tree[MAX];
vector<int> map[MAX];
bool check[MAX];
queue<int> q;

void bfs(int n)
{
    q.push(n);
    check[n] = true;

    while (!q.empty())
    {
        int k = q.front();
        q.pop();
        for (int i = 0; i < map[k].size(); i++)
        {
            if (!check[map[k][i]])
            {
                tree[map[k][i]] = k;
                check[map[k][i]] = true;
                q.push(map[k][i]);
            }
        }
    }
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> N;
    
    int u, v;
    for (int i = 0; i < N - 1; i++)
    {
        cin >> u >> v;

        map[u].push_back(v);
        map[v].push_back(u);
    }

    bfs(1);

    for (int i = 2; i <= N; i++)
    {
        cout << tree[i] << "\n";
    }
}
