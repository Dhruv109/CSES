#include <iostream>
#include <limits.h>
#include <algorithm>
#include <vector>
using namespace std;
// const int mxN = ;
const int MOD = 1e9 + 7;
typedef long long int ll;
ll i, j, k, t, n;
int arr[20];
int main()
{
    cin >> n;
    ll sum = 0;
    for (i = 0; i < n; ++i)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    ll ans = INT_MAX;
    int tempAns = INT_MAX;
    for (i = 0; i < (1 << n); ++i) // for finding all subsequences i.e 2^n
    {
        ll s2 = 0;
        for (j = 0; j < n; ++j)
        {
            if ((1 << j) & i) // checking if the jth bit is set in ith subsequence
                s2 += arr[j]; // shifting from one set to other
        }
        ans = min(ans, abs(sum - (2 * s2))); // taking the least possible difference
    }
    cout << ans;
    // this is a brute force exponential solution -> O(n*2^n)
}