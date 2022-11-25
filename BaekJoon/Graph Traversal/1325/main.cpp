#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define MAX 10001

struct cmp {
    bool operator()(pair<int, int>&a, pair<int, int>&b) {
        if (a.first == b.first) {
            return a.second > b.second;
        } else {
            return a.first < b.first;
        }
    }
};

int N, M;
vector<int> graph[MAX];
priority_queue< pair<int, int>, vector<pair<int, int>>, cmp> pq;

int check[MAX];

void clean_check(void)
{
    for (int i = 0; i <= MAX; i++)
    {
        check[i] = 0;
    }
}

int bfs(int k)
{
    queue<int> q;
    q.push(k);
    check[k] = 1;
    int number = 1;

    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int i = 0; i < graph[u].size(); i++)
        {
            if (!check[graph[u][i]])
            {
                number++;
                check[graph[u][i]] = 1;
                q.push(graph[u][i]);
            }
        }
    }
    return (number);
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;

        graph[v].push_back(u);
    }

    for (int i = 1; i <= N; i++)
    {
        int num;
        num = bfs(i);
        clean_check();
        pq.push(make_pair(num, i));
    }

    int max = pq.top().first;

    while (!pq.empty() && pq.top().first == max)
    {
        int answer = pq.top().second;
        cout << answer << " ";
        pq.pop();
    }
}