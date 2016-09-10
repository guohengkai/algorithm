/*************************************************************************
    > File Name: heap.cpp
    > Author: Guo Hengkai
    > Description: Heap
    > Created Time: Sat 10 Sep 2016 04:10:00 PM CST
 ************************************************************************/
#include "common.h"

class Heap
{
    public:
        Heap() {}
        Heap(vector<int>&& nums): nums_(std::move(nums))
        {
            MakeHeap();
            cout << "heap: ";
            PrintVector(nums_);
        }

        void Push(int x)
        {
            nums_.push_back(x);
            Up(nums_.size() - 1);
        }

        int Pop()
        {
            if (nums_.empty())
            {
                return -1;
            }
            int result = nums_[0];
            nums_[0] = nums_.back();
            nums_.pop_back();
            if (!nums_.empty())
            {
                Down(0);
            }
            return result;
        }

        bool Empty() const
        {
            return nums_.empty();
        }

    private:
        void Up(int idx)
        {
            int temp = nums_[idx];
            int parent = ((idx + 1) >> 1) - 1;
            while (parent >= 0)
            {
                if (nums_[parent] <= temp)
                {
                    break;
                }
                nums_[idx] = nums_[parent];
                idx = parent;
                parent = ((idx + 1) >> 1) - 1;
            }
            nums_[idx] = temp;
        }

        void Down(int idx)
        {
            int temp = nums_[idx];
            int child = (idx << 1) + 1;
            while (child < nums_.size())
            {
                if (child + 1 < nums_.size()
                        && nums_[child] >= nums_[child + 1])
                {
                    ++child;
                }
                if (nums_[child] >= temp)
                {
                    break;
                }
                nums_[idx] = nums_[child];
                idx = child;
                child = (idx << 1) + 1;
            }
            nums_[idx] = temp;
        }

        void MakeHeap()
        {
            for (int i = (nums_.size() >> 1) - 1; i >=0; --i)
            {
                Down(i);
            }
        }
        vector<int> nums_;
};

const int n = 10;

void HeapSort(vector<int>& nums)
{
    Heap heap(std::move(nums));
    nums.clear();
    while (!heap.Empty())
    {
        nums.push_back(heap.Pop());
    }
}

void HeapSortWithPush(vector<int>& nums)
{
    Heap heap;
    for (int num : nums)
    {
        heap.Push(num);
    }
    nums.clear();
    while (!heap.Empty())
    {
        nums.push_back(heap.Pop());
    }
}

int main()
{
    vector<int> nums = GetRandomVector(n, 100);
    cout << "origin: ";
    PrintVector(nums);
    vector<int> temp(nums);
    HeapSort(nums);
    cout << "sorted: ";
    PrintVector(nums);
    assert(IsSorted(nums));
    nums = std::move(temp);
    HeapSortWithPush(nums);
    cout << "sorted(push): ";
    PrintVector(nums);
    assert(IsSorted(nums));
    return 0;
}
