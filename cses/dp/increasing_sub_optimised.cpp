// Greedy with binary search O(nlogn) solution
// Keep a vector of sequence
// If the next number is greater, add to sequence
// If it is smaller, find the smallest number that is greater than that number
// in the sequence using binary search
// Replace the number
// Continue
// Return sequence length

#include <iostream>
#include <vector>
using namespace std;
// const int mxN = ;
const int MOD = 1e9 + 7;
typedef long long int ll;
ll i, j, k, t, n;

int binarySearch(vector<int> &s, int x)
{
    int start = 0;
    int end = s.size() - 1;
    while (start < end)
    {
        int mid = (start + end) / 2;
        if (s[mid] < x)
            start = mid + 1;
        else
            end = mid - 1;
    }
    return (start + end + 1) / 2; // adding 1 to take ceil
}

int main()
{
    cin >> n;
    int arr[n];
    for (i = 0; i < n; ++i)
        cin >> arr[i];
    vector<int> seq;
    for (i = 0; i < n; ++i)
    {

        if (seq.size() == 0 || seq[seq.size() - 1] < arr[i])
            seq.push_back(arr[i]);
        else
        {
            // else do a binary search for the smallest element greater than that number
            // int index = binarySearch(seq, arr[i]);
            auto index = lower_bound(seq.begin(), seq.end(), arr[i]);
            *index = arr[i];
        }
    }
    cout << seq.size();
    return 0;
}