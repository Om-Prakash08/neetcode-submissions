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
    Node* cloneUtils(Node* neigh, unordered_map<Node*,Node*>&mp){
        if(mp.find(neigh)!=mp.end()){
            return mp[neigh];
        }
        Node* ans = new Node(neigh->val);
        mp[neigh] = ans;
        for(Node* curr: neigh->neighbors){
            ans->neighbors.push_back(cloneUtils(curr,mp));
        }
        return ans;
    }
    Node* cloneGraph(Node* node) {
        if(node==nullptr)
         return nullptr;
        unordered_map<Node*,Node*>mp;
        Node* ans = new Node(node->val);
        mp[node] = ans;
        for(Node* neigh: node->neighbors){
            ans->neighbors.push_back(cloneUtils(neigh,mp));
        }
        return ans;
    }
};
