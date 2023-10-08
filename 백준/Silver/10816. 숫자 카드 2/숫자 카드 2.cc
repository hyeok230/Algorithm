#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <memory.h>
#include <map>
#include <algorithm>
#include <math.h>
#include <deque>
#include <climits>
#include <unordered_map>
using namespace std;

#define MAX 101



int main() {
    ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
    unordered_map<int, int> m;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int n;
        cin >> n;
        m[n]++;
    }

    cin >> N;
    for (int i = 0; i < N; i++) {
        int n;
        cin >> n;
        cout << m[n] << " ";
    }

    return 0;
}