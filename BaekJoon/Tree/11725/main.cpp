#include <iostream>
#include <vector>

using namespace std;

#define MAX 100001

int arr[MAX];
bool check[MAX];
vector<int> vec[MAX];

void dfs(int k)
{
    check[k] = true;
    for (int i = 0; i < vec[k].size(); i++)
    {
        int next = vec[k][i];
        if (!check[next])
        {
            arr[next] = k;
            dfs(next);
        }
    }
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int N, u, v;
    cin >> N;

    for (int i = 0; i < N - 1; i++)
    {
        cin >> u >> v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }

    dfs(1);

    for (int i = 2; i <= N; i++)
        cout << arr[i] << "\n";    
}