#include <iostream>
using namespace std;
const int mxN = 2 * 1e5;
const int MOD = 1e9 + 7;
typedef long long int ll;
ll i, j, k, t, n;
int arr[mxN];
int main()
{
    cin >> n;
    ll ans = 0;
    for (i = 0; i < n; ++i)
        cin >> arr[i];
    int prevN = arr[0];
    for (i = 1; i < n; ++i)
    {
        if (arr[i] < prevN)
        {
            ans += prevN - arr[i];
        }
        else
            prevN = arr[i];
    }

    cout << ans;
    return 0;
}