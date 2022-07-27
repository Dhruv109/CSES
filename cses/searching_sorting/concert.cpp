#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
// const int mxN = ;
const int MOD = 1e9 + 7;
typedef long long int ll;
ll i, j, k, t, n, m;

int main()
{
    cin >> n >> m;
    // vector<int> tickets(n); erasing from vector fucks with the time complexity as it O(n)
    // erasing from a set is O(1) [with iterator]
    // but set has no duplicate elements, so we use a multiset
    multiset<int> tickets;
    for (i = 0; i < n; ++i)
    {
        cin >> k;
        tickets.insert(k);
    }
    // sort(tickets.begin(), tickets.end()); Sets are already sorted
    for (i = 0; i < m; ++i)
    {
        cin >> t;
        auto idx = tickets.upper_bound(t); // set has inbuilt upper bound function, returns iterator with val just greater than 't'
        if (idx == tickets.begin())
        {
            cout << "-1\n";
        }
        else
        {
            idx--;
            cout << *idx << endl;
            tickets.erase(idx); // erase is the bottleneck, O(n)
        }
    }
    return 0;
    // TC - O((n+m) logn)
}