#include <iostream>
using namespace std;
const int mxN = 2 * 1e5;
const int MOD = 1e9 + 7;
typedef long long int ll;
ll i, j, k, n;
// int dp[mxN + 1][2]; // 0 -> size of subsequence, 1-> last number of subsequence
int arr[mxN];
int t[mxN + 1];
int solve(int *arr, int n, int lastInSeq)
{
    if (n == 0)
        return 0;

    // memoizing
    if (t[n] != -1)
        return t[n];

    // we can take a number if it is greater than lastInSeq
    // since we are traversing reverse we actually need a decreasing subsequence
    int ans = 0;
    if (arr[n - 1] < lastInSeq)
        ans = max(1 + solve(arr, n - 1, arr[n - 1]), solve(arr, n - 1, lastInSeq));
    else
        ans = solve(arr, n - 1, lastInSeq); // can't take this number
    return t[n] = ans;
}

int main()
{
    cin >> n;
    memset(t, -1, sizeof(t));
    for (i = 0; i < n; i++)
        cin >> arr[i];
    int ans = solve(arr, n, INT_MAX);
    cout << ans;
    return 0;
}