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
private:
    void buscar (Node* no, vector<int>& r) {
        if (no != nullptr) {
            for (Node* n: no->children) buscar (n, r);
            r.push_back (no->val);
        }
    }
public:
    vector<int> postorder(Node* root) {
        vector<int> resposta;
        buscar (root, resposta);
        return resposta;
    }
};

