/*************************************************************************
    > File Name: trie_graph.cpp
    > Author: Guo Hengkai
    > Description: trie graph
    > Created Time: Mon 12 Sep 2016 09:12:58 AM CST
 ************************************************************************/
#include "common.h"

// Only 26 lower characters
class TrieGraph
{
    public:
        explicit TrieGraph(bool use_graph = false):
            root_(0), use_graph_(use_graph)
        {
            nodes_.emplace_back();
        }

        void Build(const vector<string>& strs)
        {
            // Build trie
            for (const string& str : strs)
            {
                Add(str);
            }

            // Build trie graph
            BuildGraph();
        }

        vector<int> Find(const string& str) const
        {
            vector<int> results;
            int cur = root_;
            for (int i = 0; i < str.size(); ++i)
            {
                int idx = str[i] - 'a';
                if (!use_graph_)
                {
                    while (nodes_[cur].next[idx] == -1 && cur != root_)
                    {
                        cur = nodes_[cur].fail;
                    }
                }

                cur = nodes_[cur].next[idx];
                if (!use_graph_ && cur == -1)
                {
                    cur = root_;
                }

                int back = cur;
                while (nodes_[back].is_word)
                {
                    for (int len : nodes_[back].word_length)
                    {
                        results.push_back(i - len + 1);
                    }
                    back = nodes_[back].fail;
                }
            }
            return results;
        }

    private:
        struct Node
        {
            Node(): next(26, -1), fail(-1), is_word(false)
            {
                // Empty constructor
            }
            vector<int> next;
            int fail;
            bool is_word;
            unordered_set<int> word_length;
        };

        void Add(const string& str)
        {
            int cur = root_;
            for (const char& ch : str)
            {
                int idx = ch - 'a';
                if (nodes_[cur].next[idx] < 0)
                {
                    nodes_.emplace_back();
                    nodes_[cur].next[idx] = nodes_.size() - 1; 
                }
                cur = nodes_[cur].next[idx];
            }
            nodes_[cur].is_word = true;
            nodes_[cur].word_length.insert(str.size());
        }
        
        void BuildGraph()
        {
            if (nodes_.empty())
            {
                cout << "trie empty" << endl;
                return;
            }

            deque<int> node_queue;
            nodes_[root_].fail = root_;
            node_queue.push_back(root_);
            while (!node_queue.empty())
            {
                int parent = node_queue.front();
                node_queue.pop_front();
                Node& node = nodes_[parent];
                for (int i = 0; i < node.next.size(); ++i)
                {
                    int child;
                    if ((child = node.next[i]) != -1)
                    {
                        if (parent == root_)
                        {
                            nodes_[child].fail = root_;
                        }
                        else
                        {
                            int fail = node.fail;
                            while (nodes_[fail].next[i] == -1 && fail != root_)
                            {
                                if (nodes_[fail].next[i] != -1)
                                {
                                    break;
                                }
                                fail = nodes_[fail].fail;
                            }
                            if (nodes_[fail].next[i] == -1)
                            {
                                nodes_[child].fail = root_;
                            }
                            else
                            {
                                nodes_[child].fail = nodes_[fail].next[i];
                            }
                        }
                        node_queue.push_back(child);
                    }
                    else if (use_graph_)
                    {
                        if (parent == root_)
                        {
                            node.next[i] = root_;
                        }
                        else
                        {
                            node.next[i] = nodes_[node.fail].next[i];
                        }
                    }
                }
            }
        }

        vector<Node> nodes_;
        int root_;
        bool use_graph_;
};

int main()
{
    const vector<string> strs{
        "she", "he", "say", "shr", "her"
    };
    cout << "patterns: ";
    PrintVector(strs);

    TrieGraph trie_graph(true);
    trie_graph.Build(strs);

    const string target = "yasherhs";
    cout << "target: " << target << endl;
    vector<int> results = trie_graph.Find(target);
    cout << "result: ";
    PrintVector(results);
    return 0;
}
