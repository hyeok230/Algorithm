#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

int solution(vector<int> food_times, long long k) {
    vector<pair<int, int> > v;
    
    for (int i = 0; i < food_times.size(); ++i) {
        v.push_back(make_pair(food_times[i], i + 1));
    }
    
    sort(v.begin(), v.end());
    
    int n = food_times.size();
    int pre_time = 0;
    for (auto it = v.begin(); it != v.end(); ++it, --n) {
        long long spend_time = (long long)(it->first - pre_time) * n;
        if (spend_time == 0) continue;
        if (k - spend_time >= 0) {
            k -= spend_time;
            pre_time = it->first;
        } else {
            k %= n;
            sort(it, v.end(), compare);
            return (it+k)->second;
        }
    }
    
    return -1;
}