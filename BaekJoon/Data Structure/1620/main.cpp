#include <iostream>
#include <map>
#include <string>

using namespace std;

bool is_number(const string& str)
{
    for (char const &ch : str) {
        if (isdigit(ch) == 0)
            return false;
    }
    return true;
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int N, M;
    string str;
    map<string, int> m1;
    map<int, string> m2;

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        cin >> str;

        m1.insert(make_pair(str, i + 1));
        m2.insert(make_pair(i + 1, str));
    }

    for(int i = 0; i < M; i++)
    {
        cin >> str;

        if (is_number(str))
        {
            cout << m2.find(stoi(str))->second << "\n";
        } else {
            cout << m1.find(str)->second << "\n";
        }
    }
}