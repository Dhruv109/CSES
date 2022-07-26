#include <iostream>
using namespace std;
// const int mxN = ;
const int MOD = 1e9 + 7;
typedef long long int ll;
ll i, j, k, t, n;

int main()
{
    cin >> n;
    //  count the number of times 5 and 2 come, print the min of 2
    //  obviously numbers which are multiple of 5 will be lesser
    int ans = 0;
    while (n)
    {
        n /= 5;
        ans += n;
    }
    cout << ans;
    return 0;
}