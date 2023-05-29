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
    
    vector<int> v(10001, 0);
    for (int i = 0; i < N; i++) {
        int n;
        cin >> n;
        v[n]++;
    }

    for (int i = 0; i < 10001; i++) {
        int itr = v[i];
        for (int j = 0; j < itr; j++) {
            cout << i << "\n";
        }
    }
    return 0;
}