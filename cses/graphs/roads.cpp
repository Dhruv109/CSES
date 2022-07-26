#include <iostream>
#include <vector>
using namespace std;
const int mxN = 1e5;
const int MOD = 1e9 + 7;
typedef long long int ll;
ll j, k, t, n, m;
int isVisited[mxN + 1];
vector<int> adj[mxN + 1];
void dfs(int x)
{
    isVisited[x] = 1;
    for (auto z : adj[x])
    {
        if (!isVisited[z])
            dfs(z);
    }
}

int main()
{
    cin >> n >> m;
    // lets make an adjecency list
    int c1, c2;

    for (int i = 0; i < m; ++i)
    {
        cin >> c1 >> c2;
        adj[c1].push_back(c2);
        adj[c2].push_back(c1);
    }
    // now we have to run a dfs
    int ans = 0;
    vector<pair<int, int>> newRoads;
    for (int i = 1; i <= n; ++i)
    {
        if (!isVisited[i])
        {
            if (i != 1)
                newRoads.push_back({1, i});
            dfs(i);
            ans++;
        }
    }
    cout << ans - 1 << endl;
    for (auto x : newRoads)
        cout << x.first << " " << x.second << endl;
    return 0;
}