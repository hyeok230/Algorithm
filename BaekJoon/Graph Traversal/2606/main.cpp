#include <iostream>
#include <vector>

using namespace std;
#define MAX 101

vector<int> vec[MAX];
bool check[101];

void dfs(int k)
{
    check[k] = true;
    for (int i = 0; i < vec[k].size(); i++)
    {
        if (!check[vec[k][i]])
            dfs(vec[k][i]);
    }
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int N;
    cin >> N;

    int n;
    cin >> n;

    int answer = 0;

    for (int i = 0; i < n; i++)
    {
        int u, v;
        cin >> u >> v;

        vec[u].push_back(v);
        vec[v].push_back(u);
    }

    dfs(1);

    for (int i = 1; i <= N; i++)
    {
        if (check[i] == true)
            answer++;
    }

    cout << answer - 1;
}