#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <cmath>

using namespace std;

int calcPrice(int min, vector<int> fees) {
    if (min <= fees[0]) {
        return fees[1];
    } else {
        float f = min - fees[0]; 
        int n = fees[1] + (ceil( f / fees[2]) * fees[3]);
        int m = ceil((min - fees[0]) / fees[2]);
        return (n);
    }
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string, queue<string> > m;
    
    for (string str : records) {
        string time = str.substr(0, 5);
        string carNumber = str.substr(6, 4);
        m[carNumber].push(time);
    }
    
    map<string, queue<string>>::iterator it;
    for (it = m.begin(); it != m.end(); it++) {
        int min = 0;
        
        while (!it->second.empty()) {
            string s1 = it->second.front();
            it->second.pop();
            
            string s2;
            if (it->second.empty()) {
                s2 = "23:59";    
            } else {
                s2 = it->second.front();
                it->second.pop();
            }
            int hour = stoi(s2.substr(0, 2)) - stoi(s1.substr(0, 2));
            int m1 = stoi(s1.substr(3, 2));
            int m2 = stoi(s2.substr(3, 2));
     
            if (m2 > m1) {
                min += m2 - m1;
            } else {
                hour--;
                min += ((60 + m2) - m1); 
            }
            min += (hour * 60);
        }
       answer.push_back(calcPrice(min, fees));
    }
    
    return answer;
}