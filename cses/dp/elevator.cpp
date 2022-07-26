// kinda like 0-1ks only but with large constraints
#include <iostream>
#include <algorithm>
using namespace std;
const int mxN = 1e5;
const int MOD = 1e9 + 7;
typedef long long int ll;
ll i, j, k, t, n;
int dp[mxN + 1]; // tells min number of trips for max weight of n

int main()
{
    cin >> n >> t;
    int wt[n];
    for (i = 0; i < n; ++i)
        cin >> wt[i];
    dp[0] = INT_MAX;

    for (j = 1; j <= t; ++j)
    {
        for (i = 1; i <= n; ++i)
        {
            if (wt[i - 1] <= j)
            {
                // i can include the person in this trip or send the person in next trip
                dp[j] = min(dp[j - wt[i - 1]], 1 + dp[j]);
            }
            else
                dp[j] = 1 + dp[j];
        }
    }
    cout << dp[t];
    return 0;
}