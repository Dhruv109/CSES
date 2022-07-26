#include <iostream>
using namespace std;
// const int mxN = ;
const int MOD = 1e9 + 7;
typedef long long int ll;
ll i, j, k, t, n;

int main()
{
    cin >> n;
    if (n == 1)
        cout << "1";
    else if (n < 4)
        cout << "NO SOLUTION";
    else
    {
        for (i = 1; i <= n / 2; ++i)
            cout << 2 * i << " ";
        for (i = 1; i <= (n + 1) / 2; ++i)
            cout << 2 * i - 1 << " ";
    }
    return 0;
}