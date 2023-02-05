#include <iostream>

using namespace std;

float list[28];
float answer[8];
int main()
{
    ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	float n;
	for (int i = 0; i < 28; i++)
	{
		cin >> n;
		list[i] = n / 100;
	}

	for (int i = 0; i < 8; i++)
		answer[i];
}