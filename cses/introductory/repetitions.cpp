#include <iostream>
using namespace std;
const int mxN = 1e6;
const int MOD = 1e9 + 7;
typedef long long int ll;
ll i, j, k, t, n;

int main()
{
    string s;
    cin >> s;
    int tempAns = 1;
    int maxAns = 1;
    char prevChar = s[0];
    for (i = 1; i < s.size(); ++i)
    {
        if (s[i] == prevChar)
            tempAns++;
        else
        {

            tempAns = 1;
            prevChar = s[i];
        }
        maxAns = max(maxAns, tempAns);
    }
    cout << maxAns;
    return 0;
}