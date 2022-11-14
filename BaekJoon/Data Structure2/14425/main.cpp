#include <iostream>
#include <set>
#include <string>

using namespace std;

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    set<string> s;
    string str;
    int N, M;
    int answer = 0;

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        cin >> str;

        s.insert(str);
    }

    for (int i = 0; i < M; i++)
    {
        cin >> str;

        if (s.find(str) != s.end())
            answer++;
    }

    cout << answer << "\n";
}