#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    string S, P;
    cin >> S >> P;

    int answer = 0;

    for (int i = 0; i < P.length();) {
        int max_len = 0;
        for (int j = 0; j < S.length(); ++j) {
            int tmp = 0;
            while (P[i + tmp] == S[j + tmp]) {
                tmp++;
            }
            max_len = max(max_len, tmp);
        }
        i += max_len;
        answer++;
    }
    cout << answer;
    
    return 0;
}