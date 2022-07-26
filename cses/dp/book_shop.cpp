#include <iostream>
using namespace std;
const int mxN = 1000;
const int mxS = 1e5;
const int MOD = 1e9 + 7;
typedef long long int ll;
ll i, j, k, t, n;
int dp[mxS + 1];
int prices[mxN];
int pages[mxN];
int main()
{
    cin >> n >> t;
    for (i = 0; i < n; ++i)
        cin >> prices[i];
    for (i = 0; i < n; ++i)
        cin >> pages[i];

    // global var already initialised first row and col of dp to zero
    for (i = 1; i <= n; ++i)
    {
        for (j = t; j >= 0; --j)
        {
            if (prices[i - 1] <= j)
                dp[j] = max(pages[i - 1] + dp[j - prices[i - 1]], dp[j]);
        }
    }
    cout << dp[t];
    return 0;
}