#include <iostream>
#include <limits.h>
using namespace std;

int N, M;
char map[51][51];
char m[2][51];
int m1[51][51];
int m2[51][51];
int answer = INT_MAX;

void make_chess(int N, int M)
{
    for (int j = 0; j < M; j++)
    {
        if (j % 2 == 0)
        {
            m[0][j] = 'W';
            m[1][j] = 'B';
        } else {
            m[0][j] = 'B';
            m[1][j] = 'W';
        }
    }
}

void find_min(int m1[51][51], int m2[51][51])
{
    for (int i = 0; i < N - 8 + 1; i++)
    {
        for (int j = 0; j < M - 8 + 1; j++)
        {
            int sum1 = 0, sum2 = 0;
            for (int a = i; a < i + 8; a++)
            {
                for (int b = j; b < j + 8; b++)
                {
                    sum1 += m1[a][b];
                    sum2 += m2[a][b];
                }
            }
            answer = answer < sum1 ? answer : sum1;
            answer = answer < sum2 ? answer : sum2;
        }
    }
}

int main()
{
    ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> map[i][j];
        }
    }

    make_chess(N, M);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (i % 2 == 0)
            {
                if (map[i][j] == m[0][j])
                    m1[i][j] = 0;  
                else
                    m1[i][j] = 1;
                if (map[i][j] == m[1][j])
                    m2[i][j] = 0;
                else
                    m2[i][j] = 1;
            } else {
                if (map[i][j] == m[1][j])
                    m1[i][j] = 0;  
                else
                    m1[i][j] = 1;
                if (map[i][j] == m[0][j])
                    m2[i][j] = 0;
                else
                    m2[i][j] = 1;
            }   
        }
    }
    find_min(m1, m2);
    cout << answer;
}