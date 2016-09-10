/*************************************************************************
    > File Name: common.h
    > Author: Guo Hengkai
    > Description: Common functions and headers
    > Created Time: Sat 10 Sep 2016 01:53:31 PM CST
 ************************************************************************/
#include <cassert>
#include <climits>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;  // To simplify the implementation, not good practice

vector<int> GetRandomVector(int n, int scope = INT_MAX);
void PrintVector(const vector<int>& nums);
bool IsSorted(const vector<int>& nums);
