/*************************************************************************
    > File Name: lca.cpp
    > Author: Guo Hengkai
    > Description: Least common ancestors
    > Created Time: Fri 23 Sep 2016 11:24:37 PM CST
 ************************************************************************/
#include "common.h"

const int n = 8;

int Find(vector<int>& father, int x)
{
    if (father[x] == x)
    {
        return x;
    }
    father[x] = Find(father, father[x]);
    return father[x];
}

void Tarjan(Node* root,
        unordered_map<int, vector<pair<size_t, int>>>& questions,
        vector<bool>& visit, vector<int>& father, vector<int>& ans)
{
    int val = root->data;
    father[val] = val;
    if (root->left)
    {
        Tarjan(root->left, questions, visit, father, ans);
        father[Find(father, root->left->data)] = val;
    }
    if (root->right)
    {
        Tarjan(root->right, questions, visit, father, ans);
        father[Find(father, root->right->data)] = val;
    }

    visit[val] = true;
    for (auto& question : questions[val])
    {
        if (ans[question.first] < 0 && visit[question.second])
        {
            ans[question.first] = Find(father, question.second);
        }
    }
}

vector<int> LCA(Node* root, const vector<vector<int>>& test_cases)
{
    unordered_map<int, vector<pair<size_t, int>>> questions;
    for (size_t i = 0; i < test_cases.size(); ++i)
    {
        questions[test_cases[i][0]].push_back({i, test_cases[i][1]});
        questions[test_cases[i][1]].push_back({i, test_cases[i][0]});
    }

    vector<bool> visit(n, false);
    vector<int> ans(test_cases.size(), -1);
    vector<int> father(n);
    Tarjan(root, questions, visit, father, ans);
    return ans;
}

int main()
{
    Node* root = Vec2Tree({0, 1, 6, 2, 3, -1, 7, -1, -1, 4, 5});
    vector<vector<int>> test_cases{
        {1, 6, 0}, {2, 5, 1}, {1, 4, 1}, {0, 6, 0}, {4, 7, 0}
    };
    vector<int> ans = LCA(root, test_cases);
    for (size_t i = 0; i < test_cases.size(); ++i)
    {
        cout << "Test case " << i << ": (" << test_cases[i][0]
            << ", " << test_cases[i][1] << ") --> " << ans[i] << endl;
        assert(ans[i] == test_cases[i][2]);
        cout << "Passed." << endl;
    }
    return 0;
}
