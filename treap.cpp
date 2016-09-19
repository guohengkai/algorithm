/*************************************************************************
    > File Name: treap.cpp
    > Author: Guo Hengkai
    > Description: Treap
    > Created Time: Mon 19 Sep 2016 08:07:22 PM CST
 ************************************************************************/
#include "common.h"

class Treap
{
    public:
        Treap(): root_(nullptr) {}

        void Insert(int x)
        {
            root_ = Insert(root_, x);
        }

        void Delete(int x)
        {
            root_ = Delete(root_, x);
        }

        bool Find(int x)
        {
            return FindNode(x);
        }

        void Print()
        {
            Print(root_);
            cout << endl;
        }

        void PrintTree()
        {
            deque<pair<Node*, int>> queue;
            queue.push_back({root_, 0});
            while (!queue.empty())
            {
                auto node = queue.front();
                queue.pop_front();
                if (node.first)
                {
                    cout << "(" << node.first->val << "," << node.first->prior
                        << "," << node.second << ") ";
                    queue.push_back({node.first->left, node.second + 1});
                    queue.push_back({node.first->right, node.second + 1});
                }
            }
            cout << endl;
        }

    private:
        struct Node
        {
            int val;
            int prior;
            Node* left;
            Node* right;

            explicit Node(int v): val(v), prior(random() % 10000),
                left(nullptr), right(nullptr) {}
        };

        Node* GetNewNode(int x)
        {
            Node* node = new Node(x);
            return node;
        }

        Node* LeftRotate(Node* parent)
        {
            Node* child = parent->right;
            parent->right = child->left;
            child->left = parent;
            return child;
        }

        Node* RightRotate(Node* parent)
        {
            Node* child = parent->left;
            parent->left = child->right;
            child->right = parent;
            return child;
        }

        Node* Insert(Node* node, int x)
        {
            if (node == nullptr)
            {
                return GetNewNode(x);
            }
            if (node->val > x)
            {
                node->left = Insert(node->left, x);
                if (node->prior < node->left->prior)
                {
                    node = RightRotate(node);
                }
            }
            else if (node->val < x)
            {
                node->right = Insert(node->right, x);
                if (node->prior < node->right->prior)
                {
                    node = LeftRotate(node);
                }
            }
            return node;
        }

        Node* FindNode(int x)
        {
            Node* cur = root_;
            while (cur)
            {
                if (cur->val == x)
                {
                    break;
                }
                if (cur->val > x)
                {
                    cur = cur->left;
                }
                else
                {
                    cur = cur->right;
                }
            }
            return cur;
        }

        Node* Delete(Node* node, int x)
        {
            if (!node)
            {
                return nullptr;
            }

            if (node->val > x)
            {
                node->left = Delete(node->left, x);
            }
            else if (node->val < x)
            {
                node->right = Delete(node->right, x);
            }
            else
            {
                if (!node->left || !node->right)
                {
                    delete node;
                    return node->left ? node->left : node->right;
                }
                else
                {
                    if (node->left->prior > node->right->prior)
                    {
                        node = RightRotate(node);
                        node->right = Delete(node->right, x);
                    }
                    else
                    {
                        node = LeftRotate(node);
                        node->left = Delete(node->left, x);
                    }
                }
            }
            return node;
        }

        void Print(Node* node)
        {
            if (!node)
            {
                return;
            }
            Print(node->left);
            cout << node->val << " ";
            Print(node->right);
        }

        Node* root_;
};

const int n = 10;

int main()
{
    vector<int> nums = GetRandomVector(n, 100);
    cout << "origin: ";
    PrintVector(nums);
    cout << "---------------------------------" << endl;
    Treap tree;
    for (int num : nums)
    {
        tree.Insert(num);
        tree.PrintTree();
    }
    cout << "sorted: ";
    tree.Print();
    assert(tree.Find(nums[0]));
    assert(!tree.Find(101));
    cout << "---------------------------------" << endl;
    for (int num : nums)
    {
        tree.Delete(num);
        tree.PrintTree();
    }
    return 0;
}
