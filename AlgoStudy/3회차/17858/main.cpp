#include <iostream>
#include <vector>

using namespace std;

int n; 
long long m, a, c, x;
vector<long long> v;
int answer;

int binary_search(int target)
{
	int low = 0;
	int high = v.size() - 1;
	int mid;

	while (low <= high)
	{
		mid = (low + high) / 2;
		if (v[mid] == target)
			return mid;
		else if (v[mid] < target)
			low = mid + 1;
		else 
			high = mid - 1;
	}
	return -1;
}

int main()
{
    ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> a >> c >> x;

	long long num;

	for (int i = 0; i < n; i++)
	{
		x = (a * x + c) % m;
		v.push_back(x);
	}	

	for (int i = 0; i < n; i++)
	{
		if (binary_search(v[i]) == -1)
			continue;
		else
			answer++;
	}

	cout << answer;
}