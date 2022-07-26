#include <iostream>
#include <math.h>
using namespace std;
// const int mxN = ;
const int MOD = 1e9 + 7;
typedef long long int ll;
ll i, j, k, t, n;

int main()
{
    cin >> n;
    // 2 power 100 se jyada kuch bhi bahut jyaada hogya
    int total = 1;
    for (i = 0; i < n; ++i)
    {
        total = (total * 2) % MOD;
    }
    cout << total;
    return 0;
}