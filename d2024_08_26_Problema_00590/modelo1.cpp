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
    vector<int> postorder(Node* root) {
        vector<int> resposta;
        if (root != nullptr) {
            for (Node* n: root->children)
                for (auto v: postorder (n)) resposta.push_back (v);
            resposta.push_back (root->val);
        }
        return resposta;
    }
};

