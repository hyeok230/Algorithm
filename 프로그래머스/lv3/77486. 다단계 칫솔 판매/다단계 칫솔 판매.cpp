#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <cmath>
using namespace std;

unordered_map<string, pair<string, int> > m;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    
    for (int i = 0; i < enroll.size(); ++i) {
        m[enroll[i]] = {referral[i], 0};
    }
    
    for (int i = 0; i < seller.size(); ++i) {
        string sell = seller[i];
        int price = amount[i] * 100;
        
        while (1) {
            if (sell == "-") break;
            
            if (price * 0.1 < 1) {
                m[sell].second += price;
                if (sell == "mary") {
                cout << price << "\n";
            }
            } else {
                m[sell].second += ceil(price * 0.9);   
                if (sell == "mary") {
                cout << ceil(price * 0.9) << "\n";
            }
            }
            sell = m[sell].first;
            price -= ceil(price * 0.9);
            if (!price) break;
        }
    }
    
    for (int i = 0; i < enroll.size(); ++i) {
        answer.push_back(m[enroll[i]].second);
    }
    
    return answer;
}