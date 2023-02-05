#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n, r, c, s;
char puzzle[14][22];
vector<string> v;
int a, b;
char dir;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void search(string str)
{
	for (int y = 1; y <= r; y++)
	{
		for (int x = 1; x <= c; x++)
		{
			if (puzzle[y][x] == str[0])
			{
				a = y;
				b = x;
				int ny = y;
				int nx = x;
				for (int i = 0; i < 4; i++)
				{
					for (int j = 1; j < str.size(); j++)
					{
						ny += dy[i];
                    	nx += dx[i];

                    	if (nx < 1)
							nx = c;
						if (ny < 1)
							ny = r;
						if (nx > c)
							nx = 1;
						if (ny > r)
							ny = 1;

						if (str[j] != puzzle[ny][nx]) break;

						if (j == str.size() - 1)
						{
							if (i == 0)
								dir = 'D';
							else if (i == 1)
								dir = 'U';
							else if (i == 2)
								dir = 'R';
							else
								dir = 'L';
							return ;
						}
					}
				}
			}
		}
	}
}

int main()
{
    ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> r >> c;
		for (int y = 1; y <= r; y++)
		{
			for (int x = 1; x <= c; x++)
			{
				cin >> puzzle[y][x];
			}
		}
		cin >> s;
		string str;
		for (int j = 0; j < s; j++)
		{
			cin >> str;
			v.push_back(str);
		}
		cout << "=====================================================\n";
		cout << "Word search puzzle #" << i + 1 << "\n";

		for (int j = 0; j < s; j++)
		{
			search(v[j]);
			cout << dir << " " << a << " " << b << " " << v[j] << "\n";
		}
		cout << "\n";
	}

}