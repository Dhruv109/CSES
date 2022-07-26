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
        // sum of coins should be divisible by 3
        if ((i + j) % 3 == 0 && i <= 2 * j && j <= 2 * i)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}