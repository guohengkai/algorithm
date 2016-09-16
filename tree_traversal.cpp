/*************************************************************************
    > File Name: tree_traversal.cpp
    > Author: Guo Hengkai
    > Description: Non-recursive tree traversal
    > Created Time: Wed 14 Sep 2016 11:26:20 PM CST
 ************************************************************************/
#include "common.h"

struct Node
{
    explicit Node(int val): data(val), left(nullptr), right(nullptr)
    {
        // empty constructor
    }
    int data;
    Node* left;
    Node* right;
};

vector<int> PreOrderTraversal(Node* root)
{
    vector<int> results;
    vector<Node*> stack;
    Node* cur = root;
    while (cur || !stack.empty())
    {
        while (cur)
        {
            results.push_back(cur->data);
            stack.push_back(cur);
            cur = cur->left;
        }
        cur = stack.back();
        stack.pop_back();
        cur = cur->right;
    }
    return results;
}

vector<int> InOrderTraversal(Node* root)
{
    vector<int> results;
    vector<Node*> stack;
    Node* cur = root;
    while (cur || !stack.empty())
    {
        while (cur)
        {
            stack.push_back(cur);
            cur = cur->left;
        }
        cur = stack.back();
        stack.pop_back();
        results.push_back(cur->data);
        cur = cur->right;
    }
    return results;
}

vector<int> PostOrderTraversal(Node* root)
{
    vector<int> results;
    vector<Node*> stack;
    Node* cur = nullptr;
    Node* pre = nullptr;
    stack.push_back(root);
    while (!stack.empty())
    {
        cur = stack.back();
        if ((!cur->left && !cur->right) ||
                (pre && (pre == cur->left || pre == cur->right)))
        {
            results.push_back(cur->data);
            stack.pop_back();
            pre = cur;
        }
        else
        {
            if (cur->right)
            {
                stack.push_back(cur->right);
            }
            if (cur->left)
            {
                stack.push_back(cur->left);
            }
        }
    }
    return results;
}

Node* Vec2Tree(const vector<int>& vec)
{
    if (vec.empty())
    {
        return nullptr;
    }

    size_t n = vec.size();
    vector<Node*> nodes(n, nullptr);
    for (size_t i = n; i > 0; --i)
    {
        if (vec[i - 1] >= 0)
        {
            nodes[i - 1] = new Node(vec[i - 1]);
            size_t child = i << 1;
            if (child <= n)
            {
                nodes[i - 1]->left = nodes[child - 1];
            }
            if (child < n)
            {
                nodes[i - 1]->right = nodes[child];
            }
        }
    }
    return nodes[0];
}

int main()
{
    // To simplify, we don't delete the memory
    Node* root = Vec2Tree({1, 2, 3, 4, 5, -1, 7, -1, -1, 6, -1, -1, -1, 8});
    cout << "Preorder: ";
    PrintVector<int>({1, 2, 4, 5, 6, 3, 7, 8});
    cout << "Inorder: ";
    PrintVector<int>({4, 2, 6, 5, 1, 3, 8, 7});
    cout << "Postorder: ";
    PrintVector<int>({4, 6, 5, 2, 8, 7, 3, 1});
    cout << "--------------------------------------" << endl;
    cout << "Non-recursive version" << endl;
    cout << "Preorder: ";
    PrintVector(PreOrderTraversal(root));
    cout << "Inorder: ";
    PrintVector(InOrderTraversal(root));
    cout << "Postorder: ";
    PrintVector(PostOrderTraversal(root));
    return 0;
}
