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
private:
    Node* montar (Node* no, unordered_map<int, Node*>& mapa) {
        if (mapa.count (no->val) == 0) {
            Node* tmp = new Node (no->val, vector<Node*> (no->neighbors.size (), nullptr));
            mapa [no->val] = tmp;
            for (int i = 0; i < no->neighbors.size (); i += 1)
                tmp->neighbors [i] = montar (no->neighbors [i], mapa);
        }
        return mapa [no->val];
    }
public:
    Node* cloneGraph(Node* node) {
        if (!node) // nullptr
            return nullptr;
        unordered_map<int, Node*> mapa;
        return montar (node, mapa);
    }
};

