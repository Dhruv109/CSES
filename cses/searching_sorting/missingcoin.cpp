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
    int a[n];
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    // we will say the smallest number not possible is ans
    ll ans = 1;
    sort(a, a + n);
    for (int i = 0; i < n; ++i)
    {
        // when the element input is greater than the smallest number, we cannot make that number
        if (ans < a[i])
            break;
        // next possible smallest number that can be potential answer
        else
            ans += a[i];
    }
    cout << ans;
    return 0;
}