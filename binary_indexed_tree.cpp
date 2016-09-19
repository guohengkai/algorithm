/*************************************************************************
    > File Name: binary_indexed_tree.cpp
    > Author: Guo Hengkai
    > Description: Binary indexed tree
    > Created Time: Mon 19 Sep 2016 09:33:24 PM CST
 ************************************************************************/
#include "common.h"

class BinaryIndexedTree
{
    public:
        // 0 ~ max_num - 1
        explicit BinaryIndexedTree(int max_num): n_(max_num),
            tree_(max_num + 1) { }

        void Add(int x, int val)
        {
            ++x;
            while (x <= n_)
            {
                tree_[x] += val;
                x += Lowbit(x);
            }
        }

        int GetSum(int x)
        {
            ++x;
            int result = 0;
            while (x)
            {
                result += tree_[x];
                x -= Lowbit(x);
            }
            return result;
        }

    private:
        inline int Lowbit(int x)
        {
            return x & (-x);
        }

        int n_;
        vector<int> tree_;
};

const int max_num = 10;

int main()
{
    vector<int> nums{5, 2, 6, 4, 1, 8, 9, 0};
    vector<int> ans{0, 1, 0, 2, 4, 0, 0, 7};
    cout << "expected: ";
    PrintVector(ans);

    BinaryIndexedTree tree(max_num);
    vector<int> result;
    for (int num : nums)
    {
        result.push_back(tree.GetSum(max_num) - tree.GetSum(num - 1));
        tree.Add(num, 1);
    }
    cout << "result: ";
    PrintVector(result);
    return 0;
}
