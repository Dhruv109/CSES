// checking bipartiteness, if a graph has cycle of odd length then its not bipartite
// a bipartite graph is two colorable
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int mxN = 1e6;
const int MOD = 1e9 + 7;
typedef long long int ll;
ll i, j, k, t, n, m;
vector<int> edges[100000];
int vis[100000];
int color[100000];
bool possible = 1;
void dfs(int u, int c)
{
    if (vis[u])
        return;
    vis[u] = 1;
    color[u] = c;
    for (auto v : edges[u])
    {
        if (!vis[v])
        {
            dfs(v, c ^ 1);
        }
        else if (color[v] == c)
            possible = 0;
    }
}
int main()
{
    cin >> n >> m;
    int u, v;
    for (i = 0; i < m; ++i)
    {
        cin >> u >> v;
        u--; // 0-index
        v--;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    for (i = 0; i < n; ++i)
    {
        // dfs from every node coz graph may have components
        if (!vis[i])
            dfs(i, 0);
    }
    if (!possible)
        cout << "IMPOSSIBLE";
    else
    {
        for (i = 0; i < n; ++i)
        {
            if (color[i] == 1)
                cout << "2 ";
            else
                cout << "1 ";
        }
    }
    return 0;
}