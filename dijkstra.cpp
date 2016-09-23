/*************************************************************************
    > File Name: dijkstra.cpp
    > Author: Guo Hengkai
    > Description: Dijkstra algorithm
    > Created Time: Fri 23 Sep 2016 08:31:19 PM CST
 ************************************************************************/
#include "common.h"

const int n = 5;

vector<int> Dijkstra(const vector<vector<int>>& graph, int src)
{
    vector<int> min_dist(n, INT_MAX);
    min_dist[src] = 0;
    vector<bool> visit(n, false);
    for (int i = 0; i < n - 1; ++i)
    {
        int min_d = INT_MAX;
        int idx = -1;
        for (int j = 0; j < n; ++j)
        {
            if (!visit[j] && min_dist[j] < min_d)
            {
                min_d = min_dist[j];
                idx = j;
            }
        }
        if (idx < 0)
        {
            break;
        }
        visit[idx] = true;
        for (int j = 0; j < n; ++j)
        {
            if (!visit[j] && graph[idx][j] < INT_MAX
                    && min_dist[j] > min_dist[idx] + graph[idx][j])
            {
                min_dist[j] = min_dist[idx] + graph[idx][j];
            }
        }
    }
    return min_dist;
}

int main()
{
    vector<vector<int>> graph{
        {0, 100, 30, INT_MAX, 10},
        {INT_MAX, 0, INT_MAX, INT_MAX, INT_MAX},
        {INT_MAX, 60, 0, 60, INT_MAX},
        {INT_MAX, 10, INT_MAX, 0, INT_MAX},
        {INT_MAX, INT_MAX, INT_MAX, 50, 0}
    };
    vector<int> min_dis = Dijkstra(graph, 0);
    cout << "Minimum distance from 0: ";
    PrintVector(min_dis);
    return 0;
}
