#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    string s1, s2, answer;
    int i = 0, j = 0;

    cin >> s1 >> s2;
    
    while (i < s1.size() && j < s2.size())
    {
        if (s1[i] <= s2[j])
            answer += s1[i++];
        else
            answer += s2[j++];
    }

    while (i < s1.size())
        answer += s1[i++];
    while (j < s2.size())
        answer += s2[j++];
    
    cout << answer;
}