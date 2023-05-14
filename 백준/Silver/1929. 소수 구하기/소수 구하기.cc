#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int M, N;

bool is_prime(int n) {

    

}

int main() {
    ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> M >> N;

    vector<bool> v(N + 1, true);

    v[1]= false;
    for (int i = 2; i <= N; i++) {
        if (v[i]) {
            int j = 2;
            while (i * j <= N) {
                v[i *j] = false;
                j++;
            }
        }
    }

    for (int i = M; i <= N; i++) {
       if (v[i])
        cout << i << "\n";
    }
    return 0;
}