#include <iostream>
using namespace std;
// const int mxN = ;
const int MOD = 1e9 + 7;
typedef long long int ll;
ll i, j, k, t, n;

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> i >> j;
        ll layer = max(i, j);
        ll anchor = layer * layer - (layer - 1);
        ll ans = 0;
        if (layer & 1) // odd numbered layer go from lower bound at bottom right to upper bound at top
        {
            if (i <= j)
                ans = anchor + (layer - i);
            else
                ans = anchor - (layer - j);
        }
        else
        {
            if (i <= j)
                ans = anchor - (layer - i);
            else
                ans = anchor + (layer - j);
        }
        cout << ans << endl;
    }
    return 0;
}