#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;
const int mxN = 1e6;
const int MOD = 1e9 + 7;
typedef long long int ll;
ll i, j, k, t, n, m;

int main()
{
    // cin >> n >> k;
    // int possible = 0;
    // unordered_map<int, int> mp;
    // for (i = 0; i < n; ++i)
    // {
    //     cin >> t;

    //     if (mp.find(k - t) != mp.end())
    //     {
    //         cout << mp[k - t] << " " << i + 1;
    //         possible = 1;
    //         break;
    //     }
    //     mp[t] = i + 1;
    // }

    // if (!possible)
    //     cout << "IMPOSSIBLE";
    // return 0;

    // TWO POINTER APPROACH
    cin >> n >> k;
    vector<int> arr(n);
    for (i = 0; i < n; ++i)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    int l = 0, r = arr.size() - 1;
    while (l < r)
    {
        if (arr[l] + arr[r] > k)
            r--;
        else if (arr[l] + arr[r] < k)
            l++;
        else
        {
            cout << l + 1 << " " << r + 1;
            return 0;
        }
    }
    cout << "IMPOSSIBLE";
}
// BROTHER wow, such a simple problem is not working
// ITS COZ THE TEST CASES HAVE BEEN SPECIFICALLY DESIGNED TO CAUSE COLLISIONS IN MAP
// THUS ITS WORSE TIME COMPLEXITY OF FINDING BECOMES O(N), AS WHOLE PROGRAM BECOMES O(N^2)
// WE NEED A TWO POINTER APPROACH WITH SORTING, IT THEN BECOMES O(NLOGN)