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
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    // get the median
    int mid = arr[n / 2];
    ll ans = 0;
    for (auto x : arr)
        ans += abs(mid - x);
    cout << ans;
    return 0;
}