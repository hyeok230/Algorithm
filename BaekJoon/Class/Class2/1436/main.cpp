#include <iostream>
#include <string>
#include <limits.h>
using namespace std;

int N;

bool sixsixsix(string num)
{
    bool flag = false;
    for (int i = 0; i < num.size() - 2; i++)
    {
        if (num[i] == '6')
        {
            if (num[i + 1] == '6' && num[i + 2] =='6')
                flag = true;
        }
    }
    return flag;
}

int main()
{
    ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> N;
    int n = 0;
    for (int i = 666; i < INT_MAX; i++)
    {
        if (sixsixsix(to_string(i)))
            n++;
        if (N == n)
        {
            cout << i;
            return 0;
        }    
    }

}