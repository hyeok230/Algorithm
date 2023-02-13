#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    string n;
    while (1)
    {
        cin >> n;
        if (n == "0")
            break ; 

        string n2(n);
        reverse(n2.begin(), n2.end()); 
        for (int i = 0; i < n.size(); i++)
        {
            if (n[i] != n2[i])
            {
                cout << "no\n";
                break ;
            }
            if (i == n.size() - 1)
                cout << "yes\n";
        } 
    }
}