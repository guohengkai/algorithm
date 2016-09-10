/*************************************************************************
    > File Name: radix_sort.cpp
    > Author: Guo Hengkai
    > Description: Radix sort
    > Created Time: Sat 10 Sep 2016 03:32:49 PM CST
 ************************************************************************/
#include "common.h"

const int n = 10;
const int m = 4;
const int scope = pow(10, m);

void RadixSort(vector<int>& nums)
{
    vector<size_t> idx;
    idx.reserve(nums.size());
    for (size_t i = 0; i < nums.size(); ++i)
    {
        idx.push_back(i);
    }

    for (int k = 0, base = 1; k < m; ++k, base *= 10)
    {
        vector<int> count(10, 0);
        for (size_t i = 0; i < idx.size(); ++i)
        {
            ++count[nums[idx[i]] / base % 10];
        }
        for (size_t i = 1; i < count.size(); ++i)
        {
            count[i] += count[i - 1];
        }
        vector<size_t> new_idx(nums.size());
        for (size_t i = n; i > 0; --i)
        {
            new_idx[--count[nums[idx[i - 1]] / base % 10]] = idx[i - 1];
        }
        idx = std::move(new_idx);
    }

    vector<int> temp(nums);
    for (size_t i = 0; i < nums.size(); ++i)
    {
        nums[i] = temp[idx[i]];
    }
}

int main()
{
    vector<int> nums = GetRandomVector(n, scope);
    cout << "origin: ";
    PrintVector(nums);
    RadixSort(nums);
    cout << "sorted: ";
    PrintVector(nums);
    assert(IsSorted(nums));
    return 0;
}
