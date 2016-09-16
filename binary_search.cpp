/*************************************************************************
    > File Name: binary_search.cpp
    > Author: Guo Hengkai
    > Description: Binary search
    > Created Time: Fri 16 Sep 2016 03:35:12 PM CST
 ************************************************************************/
#include "common.h"

// first position that nums[i] >= x
size_t LowerBound(const vector<int>& nums, int x)
{
    size_t left = 0;
    size_t right = nums.size() - 1;
    size_t mid;
    while (left < right)
    {
        mid = (left + right) >> 1;
        if (nums[mid] < x)
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }
    if (nums[left] < x) ++left;
    return left;
}

// first position that nums[i] > x
size_t UpperBound(const vector<int>& nums, int x)
{
    size_t left = 0;
    size_t right = nums.size() - 1;
    size_t mid;
    while (left < right)
    {
        mid = (left + right) >> 1;
        if (nums[mid] <= x)
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }
    if (nums[left] <= x) ++left;
    return left;
}

int main()
{
    vector<int> nums{1, 2, 3, 3, 3, 4, 7, 10};
    cout << "Numbers: ";
    PrintVector(nums);

    vector<int> test_cases{3, 0, 4, 5, 11};
    for (size_t i = 0; i < test_cases.size(); ++i)
    {
        int x = test_cases[i];
        cout << "Test case " << i << ": " << x << endl;
        size_t lower = LowerBound(nums, x);
        size_t upper = UpperBound(nums, x);
        cout << "  lower bound: " << lower << ", upper bound: "
            << upper << endl;
        assert(lower == lower_bound(nums.begin(), nums.end(), x)
                - nums.begin());
        assert(upper == upper_bound(nums.begin(), nums.end(), x)
                - nums.begin());
    }

    return 0;
}
