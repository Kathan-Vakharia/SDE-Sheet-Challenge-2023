#include <bits/stdc++.h>
using namespace std;
int meRecur(int x, int n, int m)
{
    if (n == 0)
        return 1;
    // Find our {x^(n/2)}
    int tmp = meRecur(x, n / 2, m);

    tmp = (tmp * 1LL * tmp) % m;
    // If 'n' is odd, multiply by 'x'
    if (n % 2 == 1)
        tmp = (x * 1LL * tmp) % m;

    return tmp;
}
int meIter(int x, int n, int m)
{
    // Idea: We want those powers of 'x' where
    // b is turned on its binary representation
    // Eg: 3^17 = 3^(10001) = 3^16 * 3^1
    int res = 1;
    while (n > 0)
    {
        // multiply with current power of x
        if (n & 1)
            res = (res * 1LL * x) % m;

        // Move to next weight in binary
        x = (x * 1LL * x) % m;
        n /= 2;
    }
    return res;
}
int modularExponentiation(int x, int n, int m)
{
    bool is_neg = n < 0 ? true : false;

    n = abs(n);

    int res = meIter(x, n, m);

    return is_neg ? 1 / res : res;
}
