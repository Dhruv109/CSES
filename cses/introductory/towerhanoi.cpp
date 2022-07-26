#include <iostream>
using namespace std;
// const int mxN = ;
const int MOD = 1e9 + 7;
typedef long long int ll;
ll i, j, k, t, n;

void solve(int n, int from, int to, int via)
{ // TOWERS -> 1, 2, 3

    if (n == 0)
        return;
    // lets build this logically
    // we have to transfer from 1 to 3
    int ans = 0;
    // to do this we first transfer n-1 discs from 1 to 2 via 3

    solve(n - 1, from, via, to);
    cout << from << " " << to << endl;
    // now we transfer the nth disc from 1 to 3
    // now we transfer n-1 discs from 2 to 3 via 1
    solve(n - 1, via, to, from);
}

int main()
{
    cin >> n;
    // tower of hanoi 2 ki power mai solve hota hai: for n -> 2^n-1 steps needed
    cout << (1 << n) - 1 << endl;
    solve(n, 1, 3, 2);
    return 0;
}