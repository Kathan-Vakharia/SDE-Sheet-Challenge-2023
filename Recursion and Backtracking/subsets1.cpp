#include <bits/stdc++.h>
using namespace std;

void f(vector<int> &nums, int i, int sum, vector<int> &ans)
{
    // Base Case
    if (i == nums.size())
    {
        ans.push_back(sum);
    }
    else
    {
        // Take nums[i]
        f(nums, i + 1, sum + nums[i], ans);

        // Not Take nums[i]
        f(nums, i + 1, sum, ans);
    }
}
vector<int> subsetSum(vector<int> &num)
{
    vector<int> ans;
    int i = 0;
    int sum = 0;

    f(num, i, sum, ans);
    sort(ans.begin(), ans.end());

    return ans;
}
