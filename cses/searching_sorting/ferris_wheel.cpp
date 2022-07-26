#include <iostream>
#include <algorithm>
using namespace std;
// const int mxN = ;
const int MOD = 1e9 + 7;
typedef long long int ll;
ll i, j, k, t, n;

int main()
{
    cin >> n >> k; // n children, max wt -> k
    int wt[n];
    for (i = 0; i < n; ++i)
        cin >> wt[i];
    sort(wt, wt + n);
    int l = 0, r = n - 1;
    int ans = 0;
    while (l <= r)
    {

        if (wt[l] + wt[r] <= k || l == r)
        {
            ans++;
            l++;
            r--;
        }
        else
        {
            // we know wt[r]<=k thus we need to send them separately
            ans++;
            r--;
        }
    }
    cout << ans;
    return 0;
}