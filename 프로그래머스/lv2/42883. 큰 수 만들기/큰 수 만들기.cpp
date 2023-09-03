#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

string solution(string number, int k) {
    string answer = "";
    stack<char> s;
    s.push(number[0]);
    for (int i = 1; i < number.size(); i++) {
        while (!s.empty() && s.top() < number[i] && k ) {
            s.pop();
            k--;  
        } 
        s.push(number[i]);
    }
    
    while (!s.empty() && k) {
        s.pop();
        k--;
    }
    
    while (!s.empty()) {
        answer += s.top();
        s.pop();
    }
    reverse(answer.begin(), answer.end());
    return answer;
}