#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>

void set_zero(vector<vector<int>> &matrix, int row, int col)
{
    int n = matrix.size();
    int m = matrix[0].size();

    for (int i = 0; i < n; i++)
        matrix[i][col] = 0;
    for (int j = 0; j < m; j++)
        matrix[row][j] = 0;
}
void setZeros_a1(vector<vector<int>> &matrix)
{
    // Create a new matrix
    auto v = matrix;

    int n = matrix.size();    // # rows
    int m = matrix[0].size(); // # cols
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                set_zero(v, i, j);
            }
        }
    }
    matrix = v;
}
#include <bits/stdc++.h>

void setZeros2(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    vector<int> row_flag(n, 0);
    vector<int> col_flag(m, 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                // mark the row and column
                row_flag[i] = 1;
                col_flag[j] = 1;
            }
        }
    }

    // Change the cells of matrix using
    // flag arrays
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // Change to '0' if any of the row or col
            // was marked
            if (row_flag[i] == 1 || col_flag[j] == 1)
                matrix[i][j] = 0;
        }
    }
}
void setZeros(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    bool is_col0 = false; // Marker for 0th colum

    // Mark the Rows and Columns
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                // Mark ith row
                matrix[i][0] = 0;

                // Mark jth column with care!
                if (j != 0) // any other column than 0th
                    matrix[0][j] = 0;
                else
                    is_col0 = true;
            }
        }
    }
    // Change the matrix from [1,1]=>[n-1,m-1]
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;
        }
    }

    // Change 0th row first,
    // matrix[0][0] is 0th row's flag
    if (matrix[0][0] == 0)
        for (int j = 0; j < m; j++)
            matrix[0][j] = 0;

    // Change 0th column
    if (is_col0)
        for (int i = 0; i < n; i++)
            matrix[i][0] = 0;
}
int main()
{

    return 0;
}
