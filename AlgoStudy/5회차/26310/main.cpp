#include <iostream>
#include <string>
#include <queue>

using namespace std;

int N;
string s;
priority_queue<pair<float, string> > pq;
float pt, pu, rt, ru, f; 
int answer;

int main()
{
    ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < 6; i++)
    {
        cin >> s >> pt >> pu >> rt >> ru >> f;
        float n = pt * 0.56 + pu * 0.24 + rt * 0.14 + ru * 0.06 + f * 0.3;
        pq.push(make_pair(n, s)); 
    }
    int index;
    for (int i = 0; i < 6; i++)
    {
        if (pq.top().second == "Taiwan")
        {
            index = i + 1;
            break ;
        }
        pq.pop();
    }

    if (index > N % 6)
        answer = N / 6;
    else 
        answer = N / 6 + 1;
    cout << answer; 
}