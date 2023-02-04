#include <iostream>
#include <queue>
#include <string>

using namespace std;

int N;
string str;
int n;
int l[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

queue<pair<string, int> > q;
int main()
{
    ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> N;

    string str;

    for(int i = 0; i < N; i++)
    {
        cin >> str >> n;
        q.push(make_pair(str, n));
    }

    int time = 0;
    bool flag = 1;
    for (int i = 0; i < N; i++)
    {
        if (l[time] == q.front().second)
        {
            if (q.front().first != "HOURGLASS")
            {
                cout << l[time] << " YES\n";
            } 
            else 
            {
                cout << l[time] << " NO\n";
            }
        } else {
            if (q.front().first == "HOURGLASS")
            {
                if (flag)
                    flag = 0;
                else 
                    flag = 1;
            }
            cout << l[time] << " NO\n";
        }
        if (flag)
        {
            time++;
            if (time == 12)
                time = 0;
        } else {
            time--;
            if (time == -1)
                time = 11;
        }
        q.pop();   
    }
}