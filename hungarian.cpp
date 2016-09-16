/*************************************************************************
    > File Name: hungarian.cpp
    > Author: Guo Hengkai
    > Description: Hungarian algorithm
    > Created Time: Fri 16 Sep 2016 04:21:16 PM CST
 ************************************************************************/
#include "common.h"

const int m = 4;
const int n = 3;

bool Find(const vector<vector<int>>& edges, int x,
        vector<int>& result, vector<bool>& visit)
{
    for (int y : edges[x])
    {
        if (!visit[y])
        {
            visit[y] = true;
            if (result[y] == -1 || Find(edges, result[y], result, visit))
            {
                result[y] = x;
                return true;
            }

        }
    }
    return false;
}

int Hungarian(const vector<vector<int>>& edges)
{
    int count = 0;
    vector<int> result(n, -1);
    for (int i = 0; i < m; ++i)
    {
        vector<bool> visit(i, false);
        if (Find(edges, i, result, visit))
        {
            ++count;
        }
    }
    cout << "Match result: ";
    PrintVector(result);
    return count;
}

int main()
{
    vector<vector<int>> edges{
        {0, 1, 2}, {0, 1}, {1}, {1}
    };
    assert(Hungarian(edges) == 3);
    cout << "Test passed." << endl;
    return 0;
}
