#include <bits/stdc++.h>

using namespace std;

long long util(long long *arr, int start, int mid, int end)
{
    long long inv_cnt = 0;
    // Merge Procedure
    // Copy left half and right half
    vector<long long> left(mid - start + 1);
    for (int i = 0; i < left.size(); i++)
        left[i] = arr[i + start];

    vector<long long> right(end - mid);
    for (int i = 0; i < right.size(); i++)
        right[i] = arr[i + mid + 1];

    int i = 0, j = 0, k = start;
    while (i < left.size() && j < right.size())
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else // left[i] > right[j]: INVERSIONS!
        {
            arr[k] = right[j];
            inv_cnt += left.size() - i;
            j++;
        }
        k++;
    }

    while (i < left.size())
    {
        arr[k] = left[i];
        i++, k++;
    }

    // if right array has some elements => inversions!
    while (j < right.size())
    {
        arr[k] = right[j];
        j++, k++;
    }
    return inv_cnt;
}

// Merge Sort
long long count_inversions(long long *arr, int start, int end)
{
    long long inv_cnt = 0;
    if (start < end)
    {
        int mid = (start + end) / 2;
        // count inversions in left half
        inv_cnt += count_inversions(arr, start, mid);
        // count inversions in right half
        inv_cnt += count_inversions(arr, mid + 1, end);
        // count inversions of entire array
        inv_cnt += util(arr, start, mid, end);
    }
    return inv_cnt;
}
long long getInversions(long long *arr, int n)
{

    long long inv_cnt = count_inversions(arr, 0, n - 1);
    return inv_cnt;
}