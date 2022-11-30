#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;
#define MAX 201

int R, C, N;
char map[MAX][MAX];
int boom[MAX][MAX];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void print_map(void)
{
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cout << map[i][j];
        }
        cout << "\n";
    }
}

void install_boom(int T)
{
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (map[i][j] == 'O')
                continue;
            map[i][j] = 'O';
            boom[i][j] = T + 3;
        }
    }
}

void delete_boom(int T)
{
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (boom[i][j] == T)
            {
                for (int k = 0; k < 4; k++)
                {
                    int ny = i + dy[k];
                    int nx = j + dx[k];

                    if (nx < 0 || ny < 0 || nx >= C || ny >= R) continue;
                    if (map[ny][nx] == '.') continue;
                    map[ny][nx] = '.';
                }
                map[i][j] = '.';
                boom[i][j] = 0;
            }
        }
    }
}

void solution(void)
{
    int Time = 2;
    while (1)
    {
        if (Time == N + 1)
            break;
        
        if (Time % 2 == 0)
        {
            install_boom(Time);
        } else {
            delete_boom(Time);
        }
        Time++;
    }

}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> R >> C >> N;

    for (int i = 0; i < R; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < C; j++)
        {
            map[i][j] = str[j];
            if (str[j] == 'O')
            {
                boom[i][j] = 3;
            }
        }
    }
    solution();    

    print_map();
}