#include <bits/stdc++.h>
using namespace std;
int count_reverse_pairs(vector<int> &arr, int start, int mid, int end)
{
    int cnt = 0;
    int r = mid + 1;
    for (int l = start; l <= mid; l++)
    {
        while (r <= end && arr[l] > 2LL * arr[r])
            r++;

        // Update with rev pairs of type [arr[l], ...]
        cnt = cnt + r - (mid + 1);
    }
    return cnt;
}
int merge(vector<int> &arr, int start, int mid, int end)
{
    vector<int> left(mid - start + 1);
    for (int i = 0; i < left.size(); i++)
        left[i] = arr[i + start];
    vector<int> right(end - mid);
    for (int i = 0; i < right.size(); i++)
        right[i] = arr[mid + i + 1];

    int cnt = count_reverse_pairs(arr, start, mid, end);

    int i = 0, j = 0, k = start;
    while (i < left.size() && j < right.size())
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else // left[i] > right[j]
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < left.size())
        arr[k++] = left[i++];
    while (j < right.size())
        arr[k++] = right[j++];

    return cnt;
}
int ms(vector<int> &nums, int start, int end)
{
    int cnt = 0;
    if (start < end)
    {
        int mid = start + (end - start) / 2;
        // count reverse pairs in left-subarray
        int left = ms(nums, start, mid);
        // count reverse pairs in right-subarray
        int right = ms(nums, mid + 1, end);
        // count reverse pairs for this partition
        int my = merge(nums, start, mid, end);
        cnt = left + right + my;
    }
    return cnt;
}
int reversePairs(vector<int> &arr, int n)
{
    int ans = ms(arr, 0, n - 1);
    return ans;
}