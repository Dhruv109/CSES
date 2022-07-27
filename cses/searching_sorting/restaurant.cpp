#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int mxN = 1e6;
const int MOD = 1e9 + 7;
typedef long long int ll;
ll i, j, k, t, n;

int main()
{

    cin >> n;
    vector<pair<int, int>> c;
    for (i = 0; i < n; ++i)
    {
        cin >> j >> k;
        c.push_back({j, 1}); // entering time
        c.push_back({k, 0}); // leaving time
    }
    sort(c.begin(), c.end()); // We have pairs so it will be sorted lexographiclly
    // customers will be sorted according to time
    int ans = 0;
    int people = 0;
    for (auto x : c)
    {
        if (x.second)
        {
            // people entering
            people++;
            ans = max(ans, people);
        }
        else
        {
            // people leaving
            people--;
        }
    }
    cout << ans;
    return 0;
}