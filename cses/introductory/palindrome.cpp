#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;
// const int mxN = ;
const int MOD = 1e9 + 7;
typedef long long int ll;
ll i, j, k, t, n;

int main()
{
    string s;
    cin >> s;
    unordered_map<char, int> freq;
    for (i = 0; i < s.size(); ++i)
    {
        freq[s[i]]++;
    }
    int nOddFreq = 0;
    for (auto x : freq)
    {
        if (x.second & 1)
            nOddFreq++;
    }
    if (nOddFreq > 1)
        cout << "NO SOLUTION";
    else
    {
        string ans = "";
        string k = "";
        // we have even string
        char oddChar;
        for (auto x : freq)
        {
            if (x.second & 1)
                oddChar = x.first;
            for (i = 0; i < x.second / 2; ++i)
                k += x.first;
        }
        ans.append(k);
        reverse(k.begin(), k.end());

        if (nOddFreq)
            ans += oddChar;

        ans.append(k);
        cout << ans;
    }
    return 0;
}