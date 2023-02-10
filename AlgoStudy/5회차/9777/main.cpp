#include <iostream>
#include <map>
#include <string>

using namespace std;

int n;
map<int, int> m;

int main()
{
    ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < 12; i++)
        m.insert(make_pair(i + 1, 0));
    
    int id;
    string date;

    for (int i = 0; i < n; i++)
    {
        cin >> id >> date;
        date = date.substr(date.find("/") + 1);
        date = date.substr(0, date.find("/"));
        int month = stoi(date);
        m[month]++;
    }

    for (int i = 0; i < 12; i++)
    {
        cout << i + 1 << " " << m[i + 1] << "\n";
    }
}