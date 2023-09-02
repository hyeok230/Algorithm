#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int diffWord(string word, string str) {
    int count = 0;
    
    for (int i = 0; i < word.length(); i++) {
        if (word[i] != str[i]) {
            count++;
        }
    }
    return count;
}

int solution(string begin, string target, vector<string> words) {
    
    map<string, int> m;
    queue<string> q;
    m[begin] = 0;
    q.push(begin);
    
    while (!q.empty()) {
        string str = q.front();
        q.pop();
        
        for (string word : words) {
            if (diffWord(word, str) == 1 && m[word] == 0) {
                q.push(word);
                m[word] = m[str] + 1;
                if (word == target) {
                    return m[target];
                }
            }
        }   
    }
    return 0;
}