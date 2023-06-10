#include <bits/stdc++.h>
using namespace std;

bool check_freq(vector<int> &arr, int ele)
{
    int freq = 0;
    for (auto a : arr)
        if (a == ele)
            freq++;
    return freq > arr.size() / 3;
}
vector<int> majorityElementII(vector<int> &arr)
{
    int cnt1 = 0, cnt2 = 0;
    int ele1 = -1, ele2 = -1;

    for (auto a : arr)
    {
        if (cnt1 == 0 && a != ele2)
        {
            cnt1 = 1;
            ele1 = a;
        }
        else if (cnt2 == 0 && a != ele1)
        {
            cnt2 = 1;
            ele2 = a;
        }
        else if (a == ele1)
        {
            cnt1++;
        }
        else if (a == ele2)
        {
            cnt2++;
        }
        else
        {
            cnt1--;
            cnt2--;
        }
    }
    vector<int> ans;
    if (check_freq(arr, ele1))
        ans.push_back(ele1);
    if (check_freq(arr, ele2))
        ans.push_back(ele2);
    return ans;
}