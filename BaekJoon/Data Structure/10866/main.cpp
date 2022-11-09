#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, num;
    string str;
    deque<int> dq;

    cin >> n;

    for (int i = 0; i < n; i++)
    {    
        cin >> str;

        if (str == "push_front")
        {
            cin >> num;
            dq.push_front(num);
        }
        else if (str == "push_back")
        {
            cin >> num;
            dq.push_back(num);
        }
        else if (str == "pop_front")
        {
            if (!dq.size())
            {
                cout << -1 << "\n";
            } else {
                cout << dq.front() << "\n";
                dq.pop_front();
            }
        }
        else if (str == "pop_back")
        {
            if (!dq.size())
            {
                cout << -1 << "\n";
            } else {
                cout << dq.back() << "\n";
                dq.pop_back();
            }
        }
        else if (str == "size")
        {
            cout << dq.size() << "\n";
        }
        else if (str == "empty")
        {
            cout << dq.empty() << "\n";
        }
        else if (str == "front")
        {
            if (!dq.size())
            {
                cout << -1 << "\n";
            } else {
                cout << dq.front() << "\n";
            }
        }
        else if (str == "back")
        {
            if (!dq.size())
            {
                cout << -1 << "\n";
            } else {
                cout << dq.back() << "\n";
            }
        }
    }
}