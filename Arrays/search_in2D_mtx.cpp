#include<bits/stdc++.h>
using namespace std;
// Apply Binary Search to find 'target row'
int search_row(vector<vector<int>> &mat, int target)
{
    int m = mat.size();
    int n = mat[0].size();

    int tr = -1;
    int sr = 0, er = m - 1;
    while (sr <= er)
    {
        int mr = (sr + er) / 2;
        if (target >= mat[mr][0] && target <= mat[mr][n - 1])
        {
            tr = mr;
            break;
        }
        else if (target > mat[mr][n - 1])
        {
            // omit upper half
            sr = mr + 1;
        }
        else if (target < mat[mr][0])
        {
            // omit lower half
            er = mr - 1;
        }
    }
    return tr;
}
// Apply binary search in the target row, 'tr'
bool search_target(vector<vector<int>> &mat, int target, int tr)
{
    int low = 0;
    int high = mat[0].size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (mat[tr][mid] == target)
            return true;
        else if (mat[tr][mid] > target)
            high = mid - 1; // omit right half
        else
            low = mid + 1; // omit left half
    }
    return false;
}
bool searchMatrix(vector<vector<int>> &mat, int target)
{
    // Find Target Row, if it exists
    int tr = search_row(mat, target);
    if (tr == -1)
        return false;

    // Try to find 'target' in target row 'tr' using Binary Search
    bool found = search_target(mat, target, tr);

    return found;
}