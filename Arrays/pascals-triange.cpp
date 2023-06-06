#include <bits/stdc++.h>
using namespace std;

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