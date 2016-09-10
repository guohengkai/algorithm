/*************************************************************************
    > File Name: common.cpp
    > Author: Guo Hengkai
    > Description: Common functions and headers
    > Created Time: Sat 10 Sep 2016 01:55:30 PM CST
 ************************************************************************/
#include "common.h"

vector<int> GetRandomVector(int n, int scope)
{
    vector<int> nums;
    nums.reserve(n);
    for (int i = 0; i < n; ++i)
    {
        nums.push_back(rand() % scope);
    }
    return nums;
}

void PrintVector(const vector<int>& nums)
{
    for (int num : nums)
    {
        cout << num << " ";
    }
    cout << endl;
}

bool IsSorted(const vector<int>& nums)
{
    if (nums.empty())
    {
        return true;
    }

    for (size_t i = 1; i < nums.size(); ++i)
    {
        if (nums[i - 1] > nums[i])
        {
            return false;
        }
    }
    return true;
}
