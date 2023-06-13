#include<bits/stdc++.h>
using namespace std;


vector<int> twoSum(vector<int> &nums, int target)
{
    // hashmap - O(1) INS, UP, DEL
    unordered_map<int, int> mp;
    // ans wer
    vector<int> res(2);
    for (int i = 0; i < nums.size(); i++)
    {
        // element not found in the map
        if (mp.find(nums[i]) == mp.end())
        {
            mp[target - nums[i]] = i;
        }
        // element found: we've got our req. pair
        else
        {
            res[0] = mp[nums[i]];
            res[1] = i;
            break; // since exactly one solution exists
        }
    }
    return res;