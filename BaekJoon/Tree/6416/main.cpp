#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <queue>

using namespace std;
int testcase = 1;

bool bfs(map<int, vector<int>>& treeMap) {
    map<int, int> ckMap;

    for (auto iter : treeMap) {
        for (auto i : iter.second) {
            ckMap[i] = 1;
        }
    }
    int root = 0;
    for (auto iter : treeMap)
    {
        if (!ckMap[iter.first])
            root = iter.first;
    }
    ckMap.clear();
    ckMap[root] = 1;
    queue<int> q;
    q.push(root);

    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int i = 0; i < treeMap[x].size(); i++) {
            int nx = treeMap[x][i];
            if (ckMap[nx] == 1) return 0;
            ckMap[nx] = 1;
            q.push(nx);
        }
    }

    for (auto iter : treeMap) {
        if (!ckMap[iter.first]) return 0;
        for (auto i : iter.second)
        {
            if (!ckMap[i]) return 0;
        }
    }
    return 1;
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
    while(1) {
        int edgeCnt = 0;
        int u, v;
        set<int> vertex;
        map<int, vector<int>> treeMap;
        
        while(1) {
            cin >> u >> v;
            if (u == 0 && v == 0) break;
            if (u == -1 && v == -1) return 0;
            edgeCnt++;
            vertex.insert(u);
            vertex.insert(v);
            treeMap[u].push_back(v);
        }
        if (bfs(treeMap)) {
            cout << "Case " << testcase << " is a tree.\n";
        } else {
            cout << "Case " << testcase << " is not a tree.\n";
        }
        testcase++;
    }
}