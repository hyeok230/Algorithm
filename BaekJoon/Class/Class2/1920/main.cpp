#include <iostream>
#include <set>

using namespace std;

set<int> s;
int N, M;
int main()
{
    ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> N;
    int n;
    for (int i = 0; i < N; i++)
    {
        cin >> n;
        s.insert(n);
    }
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> n;
        if (s.find(n) != s.end())
            cout << "1\n";
        else 
            cout << "0\n";
    }

}