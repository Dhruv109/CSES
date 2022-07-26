#include <iostream>
using namespace std;
// const int mxN = ;
const int MOD = 1e9 + 7;
typedef long long int ll;
ll i, j, k, t, n;

int main()
{
    cin >> n;
    int ans = 0;
    for (i = 1; i < n; ++i)
    {
        cin >> t;
        ans ^= i ^ t;
    }
    ans ^= n;
    cout << ans;
    return 0;
}