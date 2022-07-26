#include <iostream>
using namespace std;
// const int mxN = ;
const int MOD = 1e9 + 7;
typedef long long int ll;
ll i, j, k, t, n;

int main()
{
    cin >> n;
    cout << n << " ";
    while (n != 1)
    {
        if (n & 1) // odd
            n = 3 * n + 1;
        else
            n /= 2;

        cout << n << " ";
    }
    return 0;
}