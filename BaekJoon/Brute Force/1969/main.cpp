#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

#define MAX 51
using namespace std;

int N, M;
int num;
string v[1000];
string answer;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    string str;
    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }

    for (int j = 0; j < M; j++)
    {
        vector<int> vec(4);
        for (int i = 0; i < N; i++)
        {
            if (v[i][j] == 'A') {
                vec[0]++;
            } else if (v[i][j] == 'C') {
                vec[1]++;
            } else if (v[i][j] == 'G') {
                vec[2]++;
            } else if (v[i][j] == 'T') {
                vec[3]++;
            }
        }
        int max = *max_element(vec.begin(), vec.end());
        num += N - max;
        for (int i = 0; i < 4; i++)
        {
            if (max == vec[i])
            {
                if (i == 0) {
                    answer += 'A';
                } else if (i == 1) {
                    answer += 'C';
                } else if (i == 2) {
                    answer += 'G';
                } else if (i == 3) {
                    answer += 'T';
                }
                break;
            }
        }  
    }

    cout << answer << "\n";
    cout << num;
}