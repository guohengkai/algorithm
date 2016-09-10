/*************************************************************************
    > File Name: merge_sort.cpp
    > Author: Guo Hengkai
    > Description: Merge sort
    > Created Time: Sat 10 Sep 2016 03:56:45 PM CST
 ************************************************************************/
#include "common.h"

const int n = 10;

void merge(vector<int>& nums, int left, int mid, int right)
{
    vector<int> sorted;
    sorted.reserve(right - left + 1);
    int l = left;
    int r = mid + 1;
    while (l <= mid && r <= right)
    {
        if (nums[l] <= nums[r])
        {
            sorted.push_back(nums[l++]);
        }
        else
        {
            sorted.push_back(nums[r++]);
        }
    }
    if (l <= mid)
    {
        copy(nums.begin() + l, nums.begin() + mid + 1,
                nums.begin() + right - mid + l);
    }
    copy(sorted.begin(), sorted.end(), nums.begin() + left);
}

void merge_sort(vector<int>& nums, int left, int right)
{
    if (left >= right)
    {
        return;
    }

    int mid = (left + right) >> 1;
    merge_sort(nums, left, mid);
    merge_sort(nums, mid + 1, right);
    merge(nums, left, mid, right);
}

void MergeSort(vector<int>& nums)
{
    merge_sort(nums, 0, nums.size() - 1);
}

int main()
{
    vector<int> nums = GetRandomVector(n, 100);
    cout << "origin: ";
    PrintVector(nums);
    MergeSort(nums);
    cout << "sorted: ";
    PrintVector(nums);
    assert(IsSorted(nums));
    return 0;
}
