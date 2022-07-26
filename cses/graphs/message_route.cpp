#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int mxN = 1e5;
const int mxM = 2 * 1e5; // small number of edges can be processed
const int MOD = 1e9 + 7;
typedef long long int ll;
ll j, k, t, n, m;
vector<int> edges[mxN + 1];
int parent[mxN + 1];
bool vis[mxN + 1];

void BFS(int x)
{
    queue<int> q;
    vis[x] = 1;
    q.push(x);
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (int z : edges[node])
        {
            if (!vis[z])
            {
                // this is a better implementation of BFS than continue one;
                vis[z] = 1;
                q.push(z);
                parent[z] = node;
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    int c1, c2;
    for (int i = 0; i < m; ++i)
    {
        cin >> c1 >> c2;
        edges[c2].push_back(c1);
        edges[c1].push_back(c2);
    }
    BFS(1);
    if (!vis[n])
        cout << "IMPOSSIBLE";
    else
    {
        vector<int> ans;

        while (n != 1)
        {
            ans.push_back(n);
            n = parent[n];
        }
        ans.push_back(1);
        cout << ans.size() << endl;
        for (int i = ans.size() - 1; i >= 0; --i)
            cout << ans[i] << " ";
    }
    return 0;
}