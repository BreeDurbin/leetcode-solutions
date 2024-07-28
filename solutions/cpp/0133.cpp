/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    map<Node*, Node*> vis;
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        if(vis.find(node) != vis.end()) return vis[node];
        Node* temp = new Node(node->val);

        vis[node] = temp;

        for(auto &neighbor : node->neighbors){
            temp->neighbors.push_back(cloneGraph(neighbor));
        }
        return temp;
    }
};