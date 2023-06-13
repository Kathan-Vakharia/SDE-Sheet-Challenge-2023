#include<bits/stdc++.h>
using namespace std;

//Code Studio Version
string fourSum(vector<int> arr, int target, int n)
{
    string ans = "No";

    sort(arr.begin(), arr.end());

    for (int i = 0; i < arr.size() - 3; i++)
    {
        for (int j = i + 1; j < arr.size() - 2; j++)
        {
            int low = j + 1;
            int high = arr.size() - 1;

            while (low < high)
            {
                int curij = arr[i] + arr[j];
                int tgt_2sum = target - curij;
                int cur_sum = arr[low] + arr[high];
                if (cur_sum == tgt_2sum)
                {
                    ans = "Yes";
                    break;
                }
                else if (cur_sum < tgt_2sum)
                {
                    low++;
                }
                else
                {
                    high--;
                }
            }
        }
    }
    return ans;
}

//LeetCode Version
