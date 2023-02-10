#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    string str;

    cin >> str;

    int length = 0, colon = 1, under = 0;
    length = str.size();
    for (int i = 6; i < length; i++)
    {
        if (str[i] == ':')
            colon++;
        else if (str[i] == '_')
            under++;
    }

    int answer = length + colon + under * 5;
    cout << answer;
}