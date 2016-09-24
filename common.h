/*************************************************************************
    > File Name: common.h
    > Author: Guo Hengkai
    > Description: Common functions and headers
    > Created Time: Sat 10 Sep 2016 01:53:31 PM CST
 ************************************************************************/
#ifndef ALGORITHM_COMMOM_H_
#define ALGORITHM_COMMOM_H_

#include <cassert>
#include <climits>
#include <cmath>
#include <algorithm>
#include <deque>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;  // To simplify the implementation, not good practice

vector<int> GetRandomVector(int n, int scope = INT_MAX);

template <typename T>
inline void PrintVector(const vector<T>& vec)
{
    for (const T& element : vec)
    {
        cout << element << " ";
    }
    cout << endl;
}

bool IsSorted(const vector<int>& nums);

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

Node* Vec2Tree(const vector<int>& vec);

#endif
