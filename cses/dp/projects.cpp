// ezy 0-1 knapsack again
#include <iostream>
#include <algorithm>
using namespace std;
const int mxN = 2 * 1e5;
const int MOD = 1e9 + 7;
typedef long long int ll;
ll i, j, k, t, n;
int dp[mxN + 1][2 * mxN + 1]; // this is important as we dont care about all 1e9 days only the start and ending days
int project[mxN][3];          // 0->start, 1->end, 2->reward
int main()
{
    cin >> n;
    int lastDay = 0;
    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < 3; ++j)
            cin >> project[i][j];
        lastDay = max(lastDay, project[i][1]);
    }
    // no explicit initialisation reqd as they are already zero
    for (i = 1; i <= n; ++i)
    {
        for (j = 1; j <= lastDay; ++j)
        {
            int startDate = project[i - 1][0];
            int lastDate = project[i - 1][1];
            int reward = project[i - 1][2];

            if (startDate < j && lastDate <= j)
            { // we can take up a project
                dp[i][j] = max(reward + dp[i - 1][j - lastDate], dp[i - 1][j]);
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    cout << dp[n][lastDay];
    return 0;
}