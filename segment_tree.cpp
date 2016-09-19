/*************************************************************************
    > File Name: segment_tree.cpp
    > Author: Guo Hengkai
    > Description: Segment tree
    > Created Time: Mon 19 Sep 2016 10:49:17 PM CST
 ************************************************************************/
#include "common.h"

const int max_num = 10;

class SegmentTree
{
    public:
        explicit SegmentTree(int max_num): n_(max_num),
            tree_((max_num << 2) | 1), count_((max_num << 2) | 1), root_(1)
        {
            // empty constructor
        }

        void Add(int x, int val)
        {
            Insert(root_, 1, n_, x + 1, x + 1, val);
        }

        int GetSum(int x)
        {
            if (x < 0)
            {
                return 0;
            }
            return GetSum(root_, 1, n_, 1, x + 1);
        }
    private:
        void Update(int cur)
        {
            tree_[cur] = count_[cur] + tree_[cur << 1] + tree_[(cur << 1) | 1];
        }

        void Insert(int cur, int left, int right, int l, int r, int val)
        {
            if (left == l && right == r)
            {
                tree_[cur] += val;
                count_[cur] += val;
                return;
            }

            int mid = (left + right) >> 1;
            if (r <= mid)
            {
                Insert(cur << 1, left, mid, l, r, val);
            }
            else if (mid < l)
            {
                Insert((cur << 1) | 1, mid + 1, right, l, r, val);
            }
            else
            {
                Insert(cur << 1, left, mid, l, mid, val);
                Insert((cur << 1) | 1, mid + 1, right, mid + 1, r, val);
            }
            Update(cur);
        }

        int GetSum(int cur, int left, int right, int l, int r)
        {
            if (left == l && right == r)
            {
                return tree_[cur];
            }
            int mid = (left + right) >> 1;
            if (r <= mid)
            {
                return GetSum(cur << 1, left, mid, l, r);
            }
            else if (mid < l)
            {
                return GetSum((cur << 1) | 1, mid + 1, right, l, r);
            }
            else
            {
                return GetSum(cur << 1, left, mid, l, mid) +
                    GetSum((cur << 1) | 1, mid + 1, right, mid + 1, r);
            }
        }

        int n_;
        vector<int> tree_;
        vector<int> count_;
        int root_;
};

int main()
{
    vector<int> nums{5, 2, 6, 4, 1, 8, 9, 0};
    vector<int> ans{0, 1, 0, 2, 4, 0, 0, 7};
    cout << "expected: ";
    PrintVector(ans);

    SegmentTree tree(max_num);
    vector<int> result;
    for (int num : nums)
    {
        result.push_back(tree.GetSum(max_num - 1) - tree.GetSum(num));
        tree.Add(num, 1);
    }
    cout << "result: ";
    PrintVector(result);
    return 0;
}
