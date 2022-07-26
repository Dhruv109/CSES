#include <iostream>
#include <set>
using namespace std;
// const int mxN = ;
const int MOD = 1e9 + 7;
typedef long long int ll;
ll i, j, k, t, n;

int main()
{
    cin >> n;
    set<int> s;
    while (n--)
    {
        cin >> t;
        s.insert(t);
    }
    cout << s.size();
    return 0;
}