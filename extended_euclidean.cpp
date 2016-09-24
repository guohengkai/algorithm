/*************************************************************************
    > File Name: extended_euclidean.cpp
    > Author: Guo Hengkai
    > Description: Extended Euclidean algorithm
    > Created Time: Sat 24 Sep 2016 07:09:58 PM CST
 ************************************************************************/
#include "common.h"

int ExtendedEuclidean(int a, int b, int& x, int& y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }

    int d = ExtendedEuclidean(b, a % b, x, y);
    int x1 = y;
    y = x - (a / b) * y;
    x = x1;
    return d;
}

int main()
{
    vector<vector<int>> test_cases{
        {3, 5, 2, 1}, {4, 10, 6, 2}, {7, 11, 1, 1}, {9, 24, 3, 3}
    };
    for (size_t i = 0; i < test_cases.size(); ++i)
    {
        int a = test_cases[i][0];
        int b = test_cases[i][1];
        int c = test_cases[i][2];
        cout << "Test case " << i << ": a = " << a << ", b = " << b <<
            ", c = " << c << endl;
        int d = test_cases[i][3];
        int x;
        int y;
        int dd = ExtendedEuclidean(a, b, x, y);
        cout << "gcd(a, b) = " << dd << endl;
        assert(dd == d);
        x *= c / dd;
        y *= c / dd;
        cout << "x = " << x << ", y = " << y << endl;
        assert(a * x + b * y == c);
        cout << "Passed." << endl;
    }
    return 0;
}
