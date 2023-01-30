#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int X;
string line;
int answer;

int main()
{
    ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> X;
    cin >> line;

    int diff = 0;

    int n = line.size();

    for (int i = 0; i < n; i++)
    {
        if (diff >= 0)
        {
            if (line[0] == 'W')
            {
                line.erase(line.begin());
                diff--;
            } else if (line[1] == 'W')
            {
                line.erase(line.begin() + 1);
                diff--;
            } else {
                line.erase(line.begin());
                diff++;
            }
        } else {
            if (line[0] == 'M')
            {
                line.erase(line.begin());
                diff++;
            } else if (line[1] == 'M')
            {
                line.erase(line.begin() + 1);
                diff++;
            } else {
                line.erase(line.begin());
                diff--;
            }
        }
        // cout << diff << endl;
        if (abs(diff) > X)
            break ;
        answer++;
    }

    cout << answer;
}