/*************************************************************************
    > File Name: topological_sort.cpp
    > Author: Guo Hengkai
    > Description: Topological sort
    > Created Time: Fri 16 Sep 2016 04:42:02 PM CST
 ************************************************************************/
#include "common.h"

const int n = 6;

vector<int> TopologicalSort(const vector<vector<int>>& edges)
{
    vector<int> in_degree(n, 0);
    for (int x = 0; x < n; ++x)
    {
        for (int y : edges[x])
        {
            ++in_degree[y];
        }
    }

    deque<int> queue;
    for (int i = 0; i < n; ++i)
    {
        if (!in_degree[i])
        {
            queue.push_back(i);
        }
    }
    vector<int> results;
    results.reserve(n);
    while (!queue.empty())
    {
        int x = queue.front();
        results.push_back(x);
        queue.pop_front();
        for (int y : edges[x])
        {
            --in_degree[y];
            if (!in_degree[y])
            {
                queue.push_back(y);
            }
        }
    }
    return results;
}

int main()
{
    vector<vector<int>> edges{
        {1, 3}, {2}, {}, {2, 4}, {5}, {}
    };
    vector<int> results = TopologicalSort(edges);
    cout << "Sorted results: ";
    PrintVector(results);
    return 0;
}
