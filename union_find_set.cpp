/*************************************************************************
    > File Name: union_find_set.cpp
    > Author: Guo Hengkai
    > Description: Union-find set
    > Created Time: Fri 16 Sep 2016 03:59:44 PM CST
 ************************************************************************/
#include "common.h"

const int n = 7;

class UnionFindSet
{
    public:
        explicit UnionFindSet(int n)
        {
            father_.reserve(n);
            for (int i = 0; i < n; ++i)
            {
                father_.push_back(i);
            }
        }

        void Add(int x, int y)
        {
            if (Find(x) != Find(y))
            {
                father_[x] = father_[y];
            }
        }

        int Find(int x)
        {
            if (father_[x] != x)
            {
                father_[x] = Find(father_[x]);
            }
            return father_[x];
        }

    private:
        vector<int> father_;
};

int main()
{
    vector<pair<int, int>> relations{
        {0, 1}, {1, 2}, {3, 5}, {2, 4}
    };
    vector<pair<int, int>> test_cases{
        {1, 2}, {0, 4}, {2, 3}, {4, 6}
    };
    vector<bool> results{
        true, true, false, false
    };

    UnionFindSet set(n);
    for (const auto& relation : relations)
    {
        set.Add(relation.first, relation.second);
    }

    for (size_t i = 0; i < test_cases.size(); ++i)
    {
        assert((set.Find(test_cases[i].first) == set.Find(test_cases[i].second))
                == results[i]);
        cout << "Test case " << i << " passed." << endl;
    }
    return 0;
}
