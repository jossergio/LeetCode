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
    vector<Node*> ultimosPorNivel;
    
    void verNivel (Node *no, int nivel) {
        if (no == nullptr)
            return; // Sumariamente; nada a fazer aqui
        if (nivel >= ultimosPorNivel.size ()) {
            // Se isso ocorrer, é em um a menos
            ultimosPorNivel.push_back (no);
        } else { // if nivel
            ultimosPorNivel [nivel]->next = no; // Com certeza, já existe um elemento
            ultimosPorNivel [nivel] = no;
        } // else if nivel
        verNivel (no->left, nivel + 1);
        verNivel (no->right, nivel + 1);
    } // verNIvel
    
public:
    Node* connect(Node* root) {
        verNivel (root, 0);
        return root;
    }
};

