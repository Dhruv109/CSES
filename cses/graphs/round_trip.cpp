#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int mxN = 1e6;
const int MOD = 1e9 + 7;
typedef long long int ll;
ll i, j, k, t, n, m;
vector<int> edges[100005];
int vis[100005];
int parent[100005];
int startNode, endNode;
bool possible;
void dfs(int u, int par)
{
    vis[u] = 1;
    for (auto v : edges[u])
    {
        if (v == par)
            continue; // dont check edge to parent;
        if (!vis[v])
        {
            parent[v] = u;
            dfs(v, u);
        }
        else
        {
            possible = 1;
            startNode = u;
            endNode = v;
        }
    }
}

int main()
{
    cin >> n >> m;
    int u, v;
    for (i = 0; i < m; ++i)
    {
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    for (i = 1; i <= n; ++i)
    {
        if (!vis[i])
            dfs(i, parent[i]);
    }
    if (possible)
    {

        int e = endNode;
        vector<int> ans;
        while (startNode != endNode)
        {
            ans.push_back(endNode);
            endNode = parent[endNode];
        }
        cout << ans.size() + 2 << endl;
        for (int x : ans)
            cout << x << " ";
        cout << endNode << " " << e;
    }
    else
        cout << "IMPOSSIBLE";
    return 0;
}

// Learnt - DFS can be used for cycle detection
// send parent as a parameter in DFS
// If edge to parent "skip it"