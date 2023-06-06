#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> nextPermutation(int n, vector<int> arr)
    {
        int idx = n - 1;

        // Find the breaking point
        while (idx > 0 && arr[idx - 1] >= arr[idx])
            idx--;

        //'arr' is not the last permutation for these numbers
        if (idx > 0)
        {
            // Swap arr[idx-1] with just greater element than it from
            // arr[idx...n-1)
            int j = n - 1;
            while (j >= idx && arr[j] <= arr[idx - 1])
                j--;
            swap(arr[j], arr[idx - 1]);
        }
        // idx == 0, if arr was the last permuation for these  numbers

        // reverse the portion, arr[idx...n-1]
        reverse(arr.begin() + idx, arr.end());

        return arr;
    }
};


/*
-Time:O()
-Space:O()
*/
int main()
{
    
    return 0;
}