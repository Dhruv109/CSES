// i think it is a mcm ka variation
#include <iostream>
using namespace std;
const int mxN = 500;
const int MOD = 1e9 + 7;
typedef long long int ll;
ll i, j, k, t, n;
int dp[501][501];
int main()
{
    int a, b;
    cin >> a >> b;

    for (i = 0; i <= a; ++i)
    {
        for (j = 0; j <= b; ++j)
        {

            if (i == j)
                dp[i][j] = 0;

            else
            {
                dp[i][j] = 1e9;
                for (int k = 1; k < i; k++)
                {
                    dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j] + 1);
                }
                for (int k = 1; k < j; k++)
                {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k] + 1);
                }
            }
        }
    }
    std::cout << dp[a][b];
    return 0;
}