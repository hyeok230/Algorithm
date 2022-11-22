#include <iostream>
#include <vector>

using namespace std;

#define MAX 100001

vector<int> vec[MAX];

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int N;
    cin >> N;

    int u, v;

    for (int i = 1; i < N; i++)
    {
        cin >> u >> v;

        vec[u].push_back(v);
        vec[v].push_back(u);
    }

    int q;
    cin >> q;

    while (q--)
    {
        int a, b;
        cin >> a >> b;

        if (a == 1)
        {
            if (vec[b].size() == 1)
            {
                cout << "no\n";
            } else {
                cout << "yes\n";
            }
        } else if (a == 2) {
            cout << "yes\n";
        }

    }
}