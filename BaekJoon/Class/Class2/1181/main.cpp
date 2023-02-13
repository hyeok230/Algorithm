#include <iostream>
#include <string>
#include <set>
using namespace std;

int N;
set<pair<int, string> > s;

int main()
{
    ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> N;
    string str;
    for (int i = 0; i < N; i++)
    {
        cin >> str;
        s.insert(make_pair(str.size(), str));
    }
    set<pair<int, string> >::iterator it;
    for (it = s.begin(); it != s.end(); it++)
    {
        cout << it->second << "\n";
    }
}