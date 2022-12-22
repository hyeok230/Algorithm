#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int N, M;
string facto[101][101];

string addNum(string n1, string n2)
{
    int sum = 0;
    string result;

    while (!n1.empty() || !n2.empty() || sum)
    {
        if (!n1.empty())
        {
            sum += n1.back() - '0';
            n1.pop_back();
        }
        if (!n2.empty())
        {
            sum += n2.back() - '0';
            n2.pop_back();
        }
        result.push_back((sum % 10) + '0');
        sum /= 10;
    }

    reverse(result.begin(), result.end());
    return result;
}

string combination(int n, int m)
{
    if (n == m || m == 0)
        return "1";

    if (facto[n][m] != "")
        return facto[n][m];
    
    facto[n][m] = addNum(combination(n-1, m-1), combination(n-1, m));
    return facto[n][m];
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> N >> M;
    cout << combination(N, M);
}