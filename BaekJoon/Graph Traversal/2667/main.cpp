#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;
#define MAX 26

int map[MAX][MAX];
int N;
priority_queue<int, vector<int>, greater<int> > pq;
queue< pair<int, int> > q;

void bfs(int y, int x)
{
    int number = 1; 
    map[y][x] = 0;
    q.push(make_pair(y, x));

    while (!q.empty())
    {
        int u = q.front().first;
        int v = q.front().second;
        q.pop();

        if (u - 1 >= 0 && v >= 0 && u - 1 < N && v < N && map[u - 1][v])
        {
            q.push(make_pair(u - 1, v));
            map[u - 1][v] = 0;
            number++;
        }
        if (u >= 0 && v + 1 >= 0 && u < N && v + 1 < N && map[u][v + 1])
        {
            q.push(make_pair(u, v + 1));
            map[u][v + 1] = 0;
            number++;
        }
        if (u + 1 >= 0 && v >= 0 && u + 1 < N && v < N && map[u + 1][v])
        {
            q.push(make_pair(u + 1, v));
            map[u + 1][v] = 0;
            number++;
        }
        if (u >= 0 && v - 1 >= 0 && u < N && v - 1 < N && map[u][v - 1])
        {
            q.push(make_pair(u, v - 1));
            map[u][v - 1] = 0;
            number++;
        }
    }
    pq.push(number);
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        string str;
        cin >> str;

        for (int j = 0; j < N; j++)
        {
            map[i][j] = str[j] - '0'; 
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (map[i][j] == 1)
            {
                bfs(i, j);
            }
        }
    }

    int num = pq.size();
    cout << num << "\n";
    for (int i = 0; i < num; i++)
    {
        cout << pq.top() << "\n";
        pq.pop();
    }
}