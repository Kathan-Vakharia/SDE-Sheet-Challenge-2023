#include <bits/stdc++.h>
using namespace std;

// Better Approach
int lengthOfLongestConsecutiveSequence1(vector<int> &arr, int n)
{
    // Given n>=1
    int ans = 1;

    sort(arr.begin(), arr.end());

    // Stores the last element of current sequence
    int last = arr[0];
    int cnt = 1;
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] == last)
        {
            continue;
        }
        else
        {
            if (arr[i] == last + 1)
            {
                cnt++;
                last = arr[i];
                ans = max(ans, cnt);
            }
            else // New Sequence begins
            {
                cnt = 1;
                last = arr[i]; // update with first ele of this seq
            }
        }
    }
    return ans;
}

// Optimal Approach
int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n)
{
    if (n <= 1)
        return n;

    unordered_set<int> st;
    for (auto a : arr)
        st.insert(a);

    int ans = 1;
    for (int i = 0; i < n; i++)
    {
        // If a number one less than arr[i] exits,
        // longer sequence might start from it;So SKIP
        if (st.find(arr[i] - 1) != st.end())
            continue;

        // Find length of sequence starting from arr[i]
        int cnt = 0;
        int x = arr[i];
        while (st.find(x++) != st.end())
            cnt++;
        // update ans if needed
        ans = max(cnt, ans);
    }
    return ans;
}