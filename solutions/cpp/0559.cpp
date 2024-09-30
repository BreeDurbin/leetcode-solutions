/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        if(!root) return 0;
        if(root->children.size() == 0) return 1;
        int depth = 0;
        for(auto& node : root->children){
            depth = max(depth, maxDepth(node));
        }
        return depth + 1;
    }
};
