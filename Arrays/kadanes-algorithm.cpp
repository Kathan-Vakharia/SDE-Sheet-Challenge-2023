#include <bits/stdc++.h>
using namespace std;

long long maxSubarraySum(int arr[], int n)
{
    // Idea: Find maxSubarraySum at every index, and
    // take maximum of it
    if (n <= 0)
        return 0;
    long long ssi = 0;
    long long gmx = 0;
    for (int i = 0; i < n; i++)
    {
        // maximum subarray sum ending at index 'i'
        ssi = max(ssi + arr[i], (long long)arr[i]);
        // update ans
        gmx = max(ssi, gmx);
    }
    return gmx;
}