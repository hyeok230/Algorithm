#include <string>
#include <vector>
#include <unordered_map>
 
using namespace std;

int win(int n) {
    switch (n) {
        case 6:
            return 1;
        case 5:
            return 2;
        case 4:
            return 3;
        case 3:
            return 4;
        case 2:
            return 5;
        default :
            return 6;
    }
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    unordered_map<int, int> m;
    int zero_num = 0;
    int same_num = 0;
    
    for (int win_num : win_nums) {
        m[win_num] = 1;
    }
    
    for (int lotto : lottos) {
        if (lotto == 0) zero_num++;
        if (m[lotto] == 1) same_num++;
    }
    
    answer.push_back(win(same_num + zero_num));
    answer.push_back(win(same_num));
    
    return answer;
}