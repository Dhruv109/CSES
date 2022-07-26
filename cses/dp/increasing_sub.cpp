// DP solution O(n^2)
#include <iostream>
using namespace std;
const int mxN = 2 * 1e5;
const int MOD = 1e9 + 7;
typedef long long int ll;
ll i, j, k, n;
// int dp[mxN + 1][2]; // 0 -> size of subsequence, 1-> last number of subsequence
int arr[mxN];
int dp[mxN + 1]; // dp[n] -> size of subsequence till val n

int main()
{
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
        dp[i] = 1; // intialise everything to 1, coz apne aap ko toh include kr hi skte hai
    }

    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < i; ++j)
        {
            // we check only from the left side of the array
            if (arr[i] > arr[j])
            {
                // can increase the length of the subsequence
                dp[i] = max(dp[i], 1 + dp[j]);
            }
        }
    }
    int ans = 0;
    for (int x : dp)
    {
        ans = max(ans, x);
    }
    cout << ans;
    return 0;
}