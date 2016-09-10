/*************************************************************************
    > File Name: quick_sort.cpp
    > Author: Guo Hengkai
    > Description: Quick sort
    > Created Time: Sat 10 Sep 2016 01:29:37 PM CST
 ************************************************************************/
#include "common.h"

const int n = 10;

void qsort(vector<int>& nums, int left, int right)
{
    int l = left;
    int r = right;
    swap(nums[l], nums[(l + r) >> 1]);
    int temp = nums[l];
    while (l < r)
    {
        while (l < r && nums[r] >= temp) --r;
        nums[l] = nums[r];
        while (l < r && nums[l] <= temp) ++l;
        nums[r] = nums[l];
    }
    nums[l] = temp;
    if (left < l - 1) qsort(nums, left, l - 1);
    if (right > l + 1) qsort(nums, l + 1, right);
}

void QuickSort(vector<int>& nums)
{
    qsort(nums, 0, nums.size() - 1);
}

int main()
{
    vector<int> nums = GetRandomVector(n, 100);
    cout << "origin: ";
    PrintVector(nums);
    QuickSort(nums);
    cout << "sorted: ";
    PrintVector(nums);
    assert(IsSorted(nums));
    return 0;
}
