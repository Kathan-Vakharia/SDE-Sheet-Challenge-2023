#include<bits/stdc++.h>

using namespace std;

void sort012_m1(int *arr, int n)
{
    int c0 = 0, c1 = 0, c2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
            c0++;
        else if (arr[i] == 1)
            c1++;
        else
            c2++;
    }

    int i = 0;
    while (i < n && c0--)
        arr[i++] = 0;
    while (i < n && c1--)
        arr[i++] = 1;
    while (i < n && c2--)
        arr[i++] = 2;
}
void sort012_m2(int *arr, int n)
{
    // move all 0s to left
    int left = -1;
    for (int i = 0; i < n; i++)
        if (arr[i] == 0)
            swap(arr[++left], arr[i]);

    // move all 2s to the right
    int right = n;
    for (int i = n - 1; i >= 0 && arr[i] != 0; i--)
        if (arr[i] == 2)
            swap(arr[i], arr[--right]);
}
void sort012(int *arr, int n)
{
    int left = -1, mid = 0, right = n;

    while (mid < right)
    {
        if (arr[mid] == 1)
        {
            mid++;
        }
        else if (arr[mid] == 0)
        {
            // move it to the left
            // Or 'replace it with the first one (if it exits)'
            left++;
            swap(arr[mid], arr[left]);
            mid++;
        }
        else if (arr[mid] == 2)
        {
            right--;
            swap(arr[mid], arr[right]);
            // DON'T increment mid
            // coz we might have brought a '0' from the end
        }
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
