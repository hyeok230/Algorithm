#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int n1, n2, n3, n4;
vector<int> n;
int answer = INT_MAX;

void calculate1(int n1, int n2)
{
    n.push_back(n1 + n2);
    n.push_back(n1 - n2);
    n.push_back(n1 * n2);
    if (n1 % n2 == 0)
        n.push_back(n1 / n2);
}

void calculate2(int n4)
{
    int cnt = n.size();
    for (int i = 0; i < cnt; i++)
    {
        n3 = n.back();
        n.pop_back();
        if (answer > n3 + n4 && n3 + n4 >= 0)
            answer = n3 + n4;
        if (answer > n3 - n4 && n3 - n4 >= 0)
            answer = n3 - n4;
        if (answer > n3 * n4 && n3 * n4 >= 0)
            answer = n3 * n4;
        if (n3 % n4 == 0 && answer > n3 / n4 && n3 / n4 >= 0)
            answer = n3 / n4;
    }
}

int main()
{
    ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> n1 >> n2 >> n4;

    calculate1(n1, n2);
    calculate2(n4);

    cout << answer;
}