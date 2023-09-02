#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue<int, vector<int>, greater<int> > pq;
    
    for (int scov : scoville) {
        pq.push(scov);
    }
    
    while (pq.top() < K) {
        answer++;
        if (pq.size() >= 2) {
            int s1 = pq.top();
            pq.pop();
            int s2 = pq.top();
            pq.pop();
            int new_s = s1 + (s2 * 2);
            pq.push(new_s);    
        } else {
            return -1;
        }
        
    }
    return answer;
}