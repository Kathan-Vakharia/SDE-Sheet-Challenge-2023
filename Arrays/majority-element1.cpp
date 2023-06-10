#include <bits/stdc++.h>

int findMajorityElement(int arr[], int n)
{
    int cnt = 0;
    int ele = 1e5 + 1;

    for (int i = 0; i < n; i++)
    {
        if (cnt == 0)
        {
            ele = arr[i];
            cnt = 1;
        }
        else if (arr[i] == ele)
            cnt++;
        else
            cnt--;
    }

    int freq = 0;
    for (int i = 0; i < n; i++)
        if (arr[i] == ele)
            freq++;
    return freq > n / 2 ? ele : -1;
}