#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

bool isPrime(int n) {
    for (int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int solution(vector<int> nums) {
    int answer = 0;
    
    
    int k = 3;
    
    vector<bool> v;
    for (int i = 0; i < k; ++i) {
        v.push_back(true);
    }
    
    for (int i = 0; i < nums.size() - k; ++i) {
        v.push_back(false);
    }
    sort(v.begin(), v.end());
    do {
        int sum = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            if (v[i] == true) {
                sum += nums[i];
            }
        }
        cout << ": " << sum;
        if (isPrime(sum)) {
            answer++;
        }
    } while (next_permutation(v.begin(), v.end()));

    return answer;
}