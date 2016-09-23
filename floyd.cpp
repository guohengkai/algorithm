/*************************************************************************
    > File Name: floyd.cpp
    > Author: Guo Hengkai
    > Description: Floyd algorithm
    > Created Time: Fri 23 Sep 2016 08:52:56 PM CST
 ************************************************************************/
#include "common.h"

const int n = 4;

vector<vector<int>> Floyd(const vector<vector<int>>& graph)
{
    vector<vector<int>> dist(graph);
    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
            {
                if (dist[i][k] < INT_MAX && dist[k][j] < INT_MAX)
                {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
    return dist;
}

int main()
{
    vector<vector<int>> graph{
        {0, 5, INT_MAX, INT_MAX},
        {50, 0, 15, 5},
        {30, INT_MAX, 0, 15},
        {15, INT_MAX, 5, 0}
    };
    auto dist = Floyd(graph);
    cout << "Distance: " << endl;
    for (const auto& vec : dist)
    {
        PrintVector(vec);
    }
    return 0;
}
