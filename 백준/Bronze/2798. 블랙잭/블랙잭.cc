#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;

int main() {
    ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> N >> M;

    int n;
    vector<int> v;
    for (int i = 0; i < N; i++) {
        cin >> n;
        v.push_back(n);
    }
    int ansN = 0;

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            for (int k = j + 1; k < N; k++) {
                int n1 = v[i];
                int n2 = v[j];
                int n3 = v[k];
                if (ansN < n1 + n2 + n3) {
                    if (n1 + n2 + n3 <= M) {
                        ansN = n1 + n2 + n3;
                    }
                }
            }
        }
    }
    cout << ansN;
    return 0;
}