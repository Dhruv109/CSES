#include <iostream>
#include <math.h>
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
        cin >> n;
        // we have 9*1 -> 1 digits, 90*2->2 digits and so on
        i = 1;
        n--;
        while (i * 9 * pow(10, i - 1) < n)
        {
            n -= i * 9 * pow(10, i - 1);
            i++;
        }
        // this is a i digit number
        ll number = pow(10, i - 1) + n / i;
        cout << number << " ";
        int pos = (n) % i;
        cout << pos << " ";
        //  int ans;
        //  if (pos == 0)
        //  {
        //      ans = number % 10;
        //  }
        //  else
        //  {
        //      for (j = 0; j < i - pos; ++j)
        //          number /= 10;
        //      ans = number % 10;
        //  }
        //  cout << ans << endl;
        string S = to_string(number);
        cout << (int)(S[pos] - '0') << endl;
    }
    return 0;
}