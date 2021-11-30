/*
Remover um elemento em uma árvore binária pelo valor
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

/*
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
}; // struct TreeNode
*/

class Solution {
private:
    TreeNode *pegarLimiteDireita (TreeNode *anterior, TreeNode *no) {
    // Algoritmo recursivo. Só para manter o conceito geral
        if (no == nullptr) // Só se for o imediado (na esquerda do nó que será retirado)
            return nullptr;
        else { // if no == nullptr
            if (no->right == nullptr) {
                if (anterior != nullptr) // É o primeiro da sequência
                    anterior->right = no->left;
                return no;
            } else { // if no->right == nullptr
                return pegarLimiteDireita (no, no->right);
            } // else if no->right == nullptr
        } // else if no == nullptr
    } // pegarLimiteDireita

public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) // Por definição, nunca virá. Só para garantir.
            return root;
        if (root->val == key) {
            TreeNode *tmp; // Não precisa inicializar aqui
            if (root->left == nullptr) { // Não há nó do lado esquerdo; joga direita
                tmp = root->right; // Indiferente se é nullptr
            } else { // if root->left == nullptr
                tmp = pegarLimiteDireita (nullptr, root->left); // Se chegou aqui, root->left não é nullptr
                if (tmp != root->left)
                    tmp->left = root->left;
                tmp->right = root->right;
            } // else if root->left == nullptr
            delete root;
            root = tmp;
        } else { // if root->val == key
            if (root->val > key)
                root->left = deleteNode (root->left, key);
            else
                root->right = deleteNode (root->right, key);
        }
        return root;
    }
};

    
/*
========
Funções auxiliares
========
*/

/*
A função abaixo foi criada só para facilitar a criação da árvore.
*/
TreeNode *adicionarElemento (TreeNode *raiz, int valor) {
// Fiz por recursividade para facilitar
    if (raiz == nullptr) {
        raiz = new TreeNode (valor, nullptr, nullptr);
    } else { // if raiz == nullptr
        if (valor < raiz->val) {
            raiz->left = adicionarElemento (raiz->left, valor);
        } else { // if valor < raiz->val
            raiz->right = adicionarElemento (raiz->right, valor);
        }
    }
    return raiz;
} // TreeNode *adicionarElemento
    
void mostrarArvore (TreeNode *no, string espacos) {
    if (no != nullptr) {
        mostrarArvore (no->left, espacos + "  ");
        cout << espacos << no->val << endl;
        mostrarArvore (no->right, espacos + "  ");
    } // if no != nullptr
} // mostrarArvore

void testar (TreeNode **arvore, int elemento) {
    cout << "Árvore antes de retirar elemento: " << elemento << ": " << endl;
    mostrarArvore (*arvore, "");
    cout << endl;
    Solution s;
    *arvore = s.deleteNode (*arvore, elemento);
    cout << "Árvore depois de retirar o elemento " << elemento << ": " << endl;
    mostrarArvore (*arvore, "");
    cout << endl;
    cout << "Finalizando iteração de teste" << endl << endl;    
} // void mostrar

int main() {
    TreeNode *arvore = nullptr;
    arvore = adicionarElemento (arvore, 0);
    testar (&arvore, 0);

    arvore = nullptr;
    arvore = adicionarElemento (arvore, 0);
    arvore = adicionarElemento (arvore, 1);
    testar (&arvore, 0);
    
    arvore = nullptr;
    arvore = adicionarElemento (arvore, 1);
    arvore = adicionarElemento (arvore, 0);
    arvore = adicionarElemento (arvore, 2);
    testar (&arvore, 1);
    
    
    arvore = nullptr;
    arvore = adicionarElemento (arvore, 5);
    arvore = adicionarElemento (arvore, 3);
    arvore = adicionarElemento (arvore, 2);
    arvore = adicionarElemento (arvore, 4);
    arvore = adicionarElemento (arvore, 6);
    arvore = adicionarElemento (arvore, 7);
    testar (&arvore, 3);

    arvore = nullptr;
    arvore = adicionarElemento (arvore, 5);
    arvore = adicionarElemento (arvore, 3);
    arvore = adicionarElemento (arvore, 2);
    arvore = adicionarElemento (arvore, 4);
    arvore = adicionarElemento (arvore, 6);
    arvore = adicionarElemento (arvore, 7);
    testar (&arvore, 7);

    arvore = nullptr;
    arvore = adicionarElemento (arvore, 5);
    arvore = adicionarElemento (arvore, 3);
    arvore = adicionarElemento (arvore, 2);
    arvore = adicionarElemento (arvore, 4);
    arvore = adicionarElemento (arvore, 6);
    arvore = adicionarElemento (arvore, 7);
    testar (&arvore, 5);

// Não vou limpar lixo em testes. Logo, a cada teste, jogo nullptr direto para iniciar uma nova árvore.
}

