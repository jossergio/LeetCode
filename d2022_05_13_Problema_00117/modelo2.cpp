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
    Node* buscar (Node* no) {
        Node* atual = no;
        while (atual != nullptr) {
            if (atual->left != nullptr)
                return atual->left;
            else {
                if (atual->right != nullptr)
                    return atual->right;
            }
            atual = atual->next;
        }
        return nullptr; // Se chegar aqui é porque não tem
    }
    
public:
    void varrer (Node* no) {
        if (no != nullptr) {
            
            if (no->left != nullptr) {
                if (no->right != nullptr)
                    no->left->next = no->right;
                else
                    no->left->next = buscar (no->next);
            }
            
            if (no->right != nullptr)
                no->right->next = buscar (no->next);
            
            varrer (no->right);
            varrer (no->left);
        }
    }
    
    Node* connect(Node* root) {
        
        varrer (root);
        
        return root;
    }
};

