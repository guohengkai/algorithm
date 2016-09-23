/*************************************************************************
    > File Name: prim.cpp
    > Author: Guo Hengkai
    > Description: Prim algorithm
    > Created Time: Fri 23 Sep 2016 09:36:06 PM CST
 ************************************************************************/
#include "common.h"

const int n = 6;

vector<pair<int, int>> Prim(const vector<vector<int>>& graph)
{
    vector<pair<int, int>> edges;
    vector<pair<int, int>> dis;
    vector<bool> visit(n, false);
    for (int i = 0; i < n; ++i)
    {
        dis.push_back({graph[0][i], 0});
    }
    visit[0] = true;
    for (int i = 1; i < n; ++i)
    {
        int min_dis = INT_MAX;
        int idx = -1;
        for (int j = 0; j < n; ++j)
        {
            if (!visit[j] && dis[j].first < min_dis)
            {
                min_dis = dis[j].first;
                idx = j;
            }
        }
        if (idx < 0)
        {
            return {};
        }
        visit[idx] = true;
        edges.push_back({dis[idx].second, idx});
        for (int j = 0; j < n; ++j)
        {
            if (!visit[j] && dis[j].first > graph[idx][j])
            {
                dis[j] = {graph[idx][j], idx};
            }
        }
    }
    return edges;
}

int main()
{
    vector<vector<int>> graph{
        {INT_MAX, 4, 2, 3, INT_MAX, INT_MAX},
        {4, INT_MAX, 5, 4, 3, INT_MAX},
        {2, 5, INT_MAX, 1, INT_MAX, 2},
        {3, 4, 1, INT_MAX, 6, 2},
        {INT_MAX, 3, INT_MAX, 6, INT_MAX, 4},
        {INT_MAX, INT_MAX, 2, 2, 4, INT_MAX}
    };
    vector<pair<int, int>> tree = Prim(graph);
    cout << "MST: ";
    for (const auto& edge : tree)
    {
        cout << "(" << edge.first << ", " << edge.second << ") ";
    }
    cout << endl;
    return 0;
}
