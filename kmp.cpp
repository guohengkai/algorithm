/*************************************************************************
    > File Name: kmp.cpp
    > Author: Guo Hengkai
    > Description: KMP algorithm
    > Created Time: Sat 10 Sep 2016 02:07:41 PM CST
 ************************************************************************/
#include "common.h"

vector<int> BuildNext(const string& target)
{
    vector<int> next(target.size() + 1, 0);
    next[0] = -1;
    size_t cur = 0;
    int k = -1;
    while (cur < target.size())
    {
        if (k == -1 || target[cur] == target[k])
        {
            ++cur;
            ++k;
            next[cur] = k;
        }
        else
        {
            k = next[k];
        }
    }
    return next;
}

vector<int> Match(const string& target, const vector<int>& next,
        const string& pattern)
{
    vector<int> results;
    size_t cur = 0;
    int k = -1;
    while (cur < target.size())
    {
        if (k == -1 || target[cur] == pattern[k])
        {
            ++cur;
            ++k;
            if (k == pattern.size())
            {
                results.push_back(cur - k);
                k = next[k];
            }
        }
        else
        {
            k = next[k];
        }
    }
    return results;
}

vector<int> MatchPattern(const string& target, const string& pattern)
{
    cout << "pattern: " << pattern << endl;
    vector<int> next = BuildNext(pattern);
    cout << "next: ";
    PrintVector(next);
    vector<int> results = Match(target, next, pattern);
    cout << "results: ";
    PrintVector(results);
    return results;
}

int main()
{
    string target = "aabacaabadabab";
    cout << "target: " << target << endl;
    cout << "-------------------------------" << endl;
    assert(MatchPattern(target, "aabad")[0] == 5);
    assert(MatchPattern(target, "aabaf").empty());
    assert(MatchPattern(target, "abab")[0] == 10);
    assert(MatchPattern(target, "aba")[1] == 6);
    return 0;
}
