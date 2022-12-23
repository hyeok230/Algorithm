#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

string N;   
int K;
int answer;
string result;

void permutation(vector<int> vt)
{
    if (result.length() > 0 && stoi(N) >= stoi(result))
    {
        answer = max(answer, stoi(result));
    }
    if (result.length() == N.length())
        return ;
    for (int i = 0; i < vt.size(); i++)
    {
        result += to_string(vt[i]);
        permutation(vt);
        result.pop_back();
    }
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    vector<int> v(K);
    for (int i = 0; i < K; i++)
        cin >> v[i];


    permutation(v);
    cout << answer;
}