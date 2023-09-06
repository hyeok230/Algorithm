#include <string>
#include <vector>
#include <iostream>
#include <string>
#include <set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    set<string> s;
    char c = words[0][0];
    int fail = 1;
    for (int i = 0; i < words.size(); ++i) {
        if (words[i][0] != c) {
            break;
        }
        if (s.count(words[i])) {
            break;
        }
        s.insert(words[i]);
        c = words[i][words[i].size() - 1];
        fail++;
    }
    cout << fail;
    if (fail == words.size() + 1) {
        answer.push_back(0);
        answer.push_back(0);
        return answer;
    }
    
    if (fail % n == 0) {
        answer.push_back(n);
        answer.push_back(fail / n);
        return answer;
    }
    
    answer.push_back(fail % n);
    answer.push_back(fail / n + 1);
    
    return answer;
}