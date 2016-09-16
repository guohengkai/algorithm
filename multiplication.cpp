/*************************************************************************
    > File Name: multiplication.cpp
    > Author: Guo Hengkai
    > Description: Big integer multiplication
    > Created Time: Fri 16 Sep 2016 10:30:38 AM CST
 ************************************************************************/
#include "common.h"

string Multiply(const string& num_a, const string& num_b)
{
    size_t na = num_a.size();
    size_t nb = num_b.size();
    vector<int> result(na + nb, 0);
    for (size_t i = 0; i < na; ++i)
    {
        int a = num_a[na - 1 - i] - '0';
        for (size_t j = 0; j < nb; ++j)
        {
            int b = num_b[nb - 1 - j] - '0';
            result[i + j] += a * b;
        }
    }

    int remain = 0;
    size_t start = 0;
    while (start < result.size() && ((result[start] += remain) > 0))
    {
        remain = result[start] / 10;
        result[start] %= 10;
        ++start;
    }
    if (start == 0)  // result is 0
    {
        start = 1;
    }

    string result_str;
    for (size_t i = start; i > 0; --i)
    {
        result_str += result[i - 1] + '0';
    }
    return result_str;
}

int main()
{
    vector<pair<string, string>> test_cases{
        {"99999", "999"}, {"3", "13242"}, {"38923893", "0"}
    };
    for (size_t i = 0; i < test_cases.size(); ++i)
    {
        string result = Multiply(test_cases[i].first, test_cases[i].second);
        cout << "Test case " << i << ": " << test_cases[i].first << " * "
            << test_cases[i].second << " = " << result << endl;
        assert(stoi(test_cases[i].first) * stoi(test_cases[i].second) ==
                stoi(result));
    }
    return 0;
}
