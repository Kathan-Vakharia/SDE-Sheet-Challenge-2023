#include <bits/stdc++.h>

using namespace std;

/* Using Merge Procedure */
vector<int> ninjaAndSortedArrays(vector<int> &arr1, vector<int> &arr2, int m, int n)
{
    int i = 0, j = 0, k = 0;
    vector<int> ans(m + n);

    while (i < m && j < n)
    {
        if (arr1[i] <= arr2[j])
        {
            ans[k] = arr1[i];
            i++;
        }
        else
        {
            ans[k] = arr2[j];
            j++;
        }
        k++;
    }
    while (i < m)
        ans[k++] = arr1[i++];
    while (j < n)
        ans[k++] = arr2[j++];

    return ans;
}

vector<int> ninjaAndSortedArrays2(vector<int> &arr1, vector<int> &arr2, int m, int n)
{
    // While the largest element in arr1 is greater than
    // smallest element in arr2; swap them
    int l = m - 1, r = 0;
    while (l >= 0 && r < n)
    {
        if (arr1[l] > arr2[r])
        {
            swap(arr1[l], arr2[r]);
            l--;
            r++; // IMP
            // Since Just moved element in arr2
            // was the greatest element in arr1
        }
        else
            break;
    }
    // Sort arr1 and arr2
    arr1.resize(m);
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.begin() + n);

    // Populate arr2 at the back of arr1
    arr1.insert(arr1.end(), arr2.begin(), arr2.begin() + n);

    return arr1;
}