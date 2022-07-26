#include <iostream>
#include <bitset>
using namespace std;
const int mxN = 16;
const int MOD = 1e9 + 7;
typedef long long int ll;
ll i, j, k, t;

int main()
{
    int n;
    cin >> n;
    for (i = 0; i < (1 << n); ++i)
    {
        ll g = i ^ (i >> 1); // xoring the number with itself shifted once to right
        bitset<16> x(g);
        for (j = 0; j < n; ++j)
            cout << x[j];
        cout << endl;
    }
    return 0;
}