/*************************************************************************
    > File Name: kruskal.cpp
    > Author: Guo Hengkai
    > Description: Kruskal algorithm
    > Created Time: Fri 23 Sep 2016 10:58:23 PM CST
 ************************************************************************/
#include "common.h"

const int n = 6;

int Find(vector<int>& father, int x)
{
    if (father[x] == x)
    {
        return x;
    }
    father[x] = Find(father, father[x]);
    return father[x];
}

void Merge(vector<int>& father, int x, int y)
{
    int px = Find(father, x);
    int py = Find(father, y);
    if (px != py)
    {
        father[px] = py;
    }
}

vector<pair<int, int>> Kruskal(vector<vector<int>>& graph)
{
    sort(graph.begin(), graph.end(),
            [](const vector<int>& v1, const vector<int>& v2)
            {
                return v1.back() < v2.back();
            });

    vector<pair<int, int>> edges;
    vector<int> father(n);
    for (int i = 0; i < n; ++i)
    {
        father[i] = i;
    }
    for (const auto& edge : graph)
    {
        if (Find(father, edge[0]) != Find(father, edge[1]))
        {
            Merge(father, edge[0], edge[1]);
            edges.push_back({edge[0], edge[1]});
            if (edges.size() >= n - 1)
            {
                break;
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
    vector<vector<int>> graph_edge;
    for (int i = 0; i < n - 1; ++i)
        for (int j = i + 1; j < n; ++j)
        {
            if (graph[i][j] < INT_MAX)
            {
                graph_edge.push_back({i, j, graph[i][j]});
            }
        }
    vector<pair<int, int>> tree = Kruskal(graph_edge);
    cout << "MST: ";
    for (const auto& edge : tree)
    {
        cout << "(" << edge.first << ", " << edge.second << ") ";
    }
    cout << endl;
    return 0;
}

