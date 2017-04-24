//133. Clone Graph
//Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.

//
//OJ's undirected graph serialization:
//Nodes are labeled uniquely.
//
//We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.
//As an example, consider the serialized graph {0,1,2#1,2#2,2}.
//
//The graph has a total of three nodes, and therefore contains three parts as separated by #.
//
//First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
//Second node is labeled as 1. Connect node 1 to node 2.
//Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
//Visually, the graph looks like the following:
//
//       1
//      / \
//     /   \
//    0 --- 2
//         / \
//         \_/




#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <limits.h>
#include <queue>

using namespace std;


// * Definition for undirected graph.
struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node)
            return NULL;
        unordered_map<int,UndirectedGraphNode*> m,m1;
        queue<UndirectedGraphNode*> q;
        q.push(node);
        UndirectedGraphNode *current;
        while (q.size()){
            current = q.front();
            q.pop();
            m1[current->label] = new UndirectedGraphNode(current->label);
            m[current->label] = current;
            for (vector<UndirectedGraphNode *>::iterator it = current->neighbors.begin(); it != current->neighbors.end(); ++it){
                if (m.find((*it)->label) == m.end())
                    q.push(*it);
            }
        }
        for (auto it = m1.begin(); it != m1.end(); ++it){
            for (auto it2 = m[it->first]->neighbors.begin(); it2 != m[it->first]->neighbors.end(); ++it2)
                it->second->neighbors.push_back(m1[(*it2)->label]);
        }
        return m1[node->label];
    }
};

int main() {
    Solution s;

    return 0;
}

