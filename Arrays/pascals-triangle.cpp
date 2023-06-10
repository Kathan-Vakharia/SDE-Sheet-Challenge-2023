#include <bits/stdc++.h>
using namespace std;

// Calculating nCk optimally
/*
- Time:O(k)
- Space:O(1)
*/
int nCk(int n, int k)
{
    long long res = 1;
    for (int i = 0; i < k; i++)
    {
        res = res * (n - i);
        res = res / (i + 1);
    }
    return (int)res;
}

// Print rth row of pascal's triangle
/*
- Time:O(r)
- Space:O(r) to store ans
*/
vector<int> printPascalRow(int n)
{
    //'n+1' elements, and first and last element is nC0 = 1= nCn
    vector<int> row(n + 1, 1);
    long long tmp = 1;

    // calculating remaining entries optimally
    for (int e = 1; e < row.size(); e++)
    {
        tmp = tmp * (n - e + 1);
        tmp = tmp / e;

        row[e] = (int)tmp;
    }
    return row;
}

// Assume 0 based indexing
int printPascalEntry(int r, int c)
{
    return nCk(r, c);
}

// Printing Pascal's Triangle
/*
- Time:O(n^2)
- Space:O(n^2) used to store ans
*/
vector<vector<long long int>> printPascal(int n)
{
    // Output
    vector<vector<long long int>> ans;

    // We will add 'rows' to our ans one by one
    for (int r = 0; r < n; r++)
    {
        // #entries in 'r'th row is 'r+1'
        vector<long long> row(r + 1, 1);
        // Start filling entries except 0th and last.
        for (int e = 1; e < row.size() - 1; e++)
        {
            row[e] = ans[r - 1][e - 1] + ans[r - 1][e];
        }
        // Add 'row' to our answer
        ans.push_back(row);
    }

    return ans;
}

/*
-Time:O()
-Space:O()
*/
int main()
{

    return 0;
}