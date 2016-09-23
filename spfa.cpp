/*************************************************************************
    > File Name: spfa.cpp
    > Author: Guo Hengkai
    > Description: SPFA algorithm
    > Created Time: Fri 23 Sep 2016 09:22:51 PM CST
 ************************************************************************/
#include "common.h"

const int n = 5;

vector<int> SPFA(const vector<vector<int>>& graph, int src)
{
    vector<int> count(n, 0);
    vector<bool> visit(n, false);
    vector<int> dist(n, INT_MAX);
    deque<int> queue;
    dist[src] = 0;
    count[src] = 1;
    visit[src] = true;
    queue.push_back(src);
    while (!queue.empty())
    {
        int x = queue.front();
        queue.pop_front();
        visit[x] = false;
        for (int i = 0; i < n; ++i)
        {
            if (graph[x][i] < INT_MAX)
            {
                if (dist[i] > dist[x] + graph[x][i])
                {
                    dist[i] = dist[x] + graph[x][i];
                    if (!visit[i])
                    {
                        visit[i] = true;
                        ++count[i];
                        if (count[i] >= n)
                        {
                            return {};
                        }
                        queue.push_back(i);
                    }
                }
            }
        }
    }
    return dist;
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
    vector<int> min_dis = SPFA(graph, 0);
    cout << "Minimum distance from 0: ";
    PrintVector(min_dis);
    return 0;
}
