#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int A, B, V;

int main() {
    ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> A >> B >> V;

    int left = V - A;
    int up = A - B;

    int num = 1;
    if (left == 0) {
        cout << num;
        return 0;
    }
    int ret = left / up;
    if (left % up)
        ret++;
    cout << ret + 1;
    
    return 0;
}