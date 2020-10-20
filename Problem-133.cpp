// Problem - 133

// https://leetcode.com/problems/clone-graph/

// O(n) time complexity and O(n) space complexity solution using dfs

class Solution {
    unordered_map <Node*, Node*> copyNodes;
public:
    
    Node* cloneGraph(Node* node) {
        if(!node)
            return NULL;
        if(copyNodes.find(node) == copyNodes.end()){
            Node* curr = new Node(node->val);
            copyNodes[node] = curr;
            for(auto n : node->neighbors) {
                (curr->neighbors).push_back(cloneGraph(n));
            }
        }
        return copyNodes[node];
    }
};
