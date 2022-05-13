/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
private:
    vector<stack<Node*>> niveis;
public:
    
    void emOrdem (Node* no, int nivel) {
        if (no != nullptr) {
            if ((nivel + 1) > niveis.size ())
                niveis.push_back (stack<Node*> ());
            niveis [nivel].push (no);
            emOrdem (no->left, nivel + 1);
            emOrdem (no->right, nivel + 1);
        }
    }
    
    Node* connect(Node* root) {
        
        emOrdem (root, 0);
        
        for (vector<stack<Node*>>::iterator i = niveis.begin (); i != niveis.end (); i++) {
            Node* sequenciador = nullptr;
            
            stack<Node*> nivel = *i;
            
            while (! nivel.empty ()) {
                nivel.top ()->next = sequenciador;
                sequenciador = nivel.top ();
                nivel.pop ();
            }
        }
        return root;
    }
};

