#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;
const int mxN = 1e6;
const int MOD = 1e9 + 7;
typedef long long int ll;
ll i, j, k, t, n, m;
vector<pair<int, int>> edges[100005];

// dijsktra algorithm

int main()
{
    cin >> n >> m;
    int u, v, wt;
    for (int i = 0; i < m; ++i)
    {
        cin >> u >> v >> wt;
        u--;
        v--;
        edges[u].push_back({wt, v});
    }
    // source is node 1;

    // pq of {dist, node}
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    // Initialising dist to INFINITY
    vector<ll> dist(n + 1, LLONG_MAX);
    dist[0] = 0;

    // starting from source
    pq.push({0, 0});
    while (!pq.empty())
    {
        auto [curDist, u] = pq.top();
        pq.pop();
        if (dist[u] != curDist)
            continue;
        for (auto &[wt, v] : edges[u])
        {
            if (dist[v] > dist[u] + wt)
            {
                dist[v] = dist[u] + wt;
                pq.push({dist[v], v});
            }
        }
    }
    for (int i = 0; i < n; ++i)
        cout << dist[i] << " ";
    return 0;
}