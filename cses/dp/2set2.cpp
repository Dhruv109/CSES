// kinda like knapsack only
// count equal sum partition
#include <iostream>
using namespace std;
const int mxN = 500;
const int mxS = (500 * 501) / 2;
const int MOD = 1e9 + 7;
typedef long long int ll;
ll i, j, k, t, n;
int dp[mxN + 1][mxS + 1]; // number of subsets that can be made with a given sum
int main()
{
    cin >> n;
    int sum = n * (n + 1) / 2;
    if (sum & 1)
    {
        cout << "0";
    }
    else
    {
        sum /= 2;
        for (i = 0; i <= n; ++i)
        {
            dp[i][0] = 1; // if sum is 0 then we can have 1 way that is empty subsets
        }

        for (i = 1; i <= n; ++i)
        {
            for (j = 1; j <= sum; ++j)
            {
                if (i <= j)
                    dp[i][j] = (dp[i - 1][j - i] + dp[i - 1][j]) % MOD;
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        cout << dp[n - 1][sum]; // this is the important trick,
                                // by considering numbers till only n-1
                                // we force the n to go to the other set
                                // thus counting each pair only once
    }
    return 0;
}