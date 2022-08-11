#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
const int mxN = 1e6;
const int MOD = 1e9 + 7;
typedef long long int ll;
ll i, j, k, t, n, m;

int main()
{
    cin >> n;
    // kadene's algo
    ll sum = 0, maxSum = -1e9;
    for (int i = 0; i < n; ++i)
    {
        cin >> t;
        sum += t;
        maxSum = max(maxSum, sum);
        if (sum < 0)
            sum = 0;
    }
    cout << maxSum;
    return 0;
}