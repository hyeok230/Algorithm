#include <iostream>

using namespace std;

int list[8];

int main()
{
    ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 8; i++)
		cin >> list[i];
	
	for (int i = 0; i < 8; i++)
	{
		if (list[i] != i + 1)
			break ;
		if (i == 7)
		{
			cout << "ascending";
			return 0;
		}
	}

	for (int i = 0; i < 8; i++)
	{
		if (list[i] != 8 - i)
			break ;
		if (i == 7)
		{
			cout << "descending";
			return 0;
		}
	}
	cout << "mixed";
}