#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N;

int main() {
    ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> N;
    vector<int> v;
    int n;
    for (int i = 0; i < N; i++) {
        cin >> n;
        v.push_back(n);
    }
    sort(v.begin(), v.end());
    // reverse(v.begin(), v.end());

    for (int i = 0; i < N; i++) {
        cout << v[i] << "\n";
    }
    return 0;
}