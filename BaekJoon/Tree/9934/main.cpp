#include <iostream>
#include <vector>

using namespace std;

vector<int> v[10];
int arr[100000];

void insert_tree(int depth, int start, int end)
{
    if (start >= end)
        return ;
    int mid = (start + end) / 2;
    v[depth].push_back(arr[mid]);
    insert_tree(depth + 1, start, mid);
    insert_tree(depth + 1, mid + 1, end);
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int k;
    cin >> k;

    int idx = 0;
    int num;
    while (cin >> num) {
        arr[idx++] = num;
    }
    insert_tree(0, 0, idx);

    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << "\n";
    }

}