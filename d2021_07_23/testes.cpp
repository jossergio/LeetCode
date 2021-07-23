/* struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode () : val (0), left (nullptr), right (nullptr) {}
    TreNode (int x): val (x), left (nullptr), right (nullprt) {}
    TreeNode (int x, TreeNode *l, TreeNode *r) : val (x), left (l), right (r) {}
}; // TreeNode
*/

bool temUm (TreeNode *t) {
    if (t != nullptr)
        if (t->val == 1)
            return true; // Agilizar
        else
            return temUm (t->left) || temUm (t->right);
    return false;
} // temUm

void imprimir (TreeNode *t, int espaco = 1) {
    if (t != nullptr) {
        imprimir (t->left, espaco + 1);
        for (int a = 0; a < espaco; a++)
            std::cout << "  ";
        std::cout << t->val << std::endl;
        imprimir (t->right, espaco + 1);
    } // if t != nullptr
}

    TreeNode *pruneTree (TreeNode *root) {
        if (root != nullptr) {
            if (!temUm (root->left))
                root->left = nullptr; // Não tem otimização de memória. É um desafio!
            else
                root->left = pruneTree (root->left);
            if (!temUm (root->right))
                root->right = nullptr; // Idem.
            else
                root->right = pruneTree (root->right);
            if (root->val == 0 && root->left == nullptr && root->right == nullptr)
                root = nullptr;
        } // if root != nullptr
        return root; // É lógico!
    } // pruneTree

int main() {
    TreeNode *arvore = new TreeNode (1);
    arvore->left = new TreeNode (0);
    arvore->right = new TreeNode (1);
    arvore->left->left = new TreeNode (1);
    arvore->left->right = new TreeNode (0);
    std::cout << "Árvore: " << temUm (arvore) << std::endl;
    std::cout << "Esquerdo: " << temUm (arvore->left) << std::endl;
    std::cout << "Direito: " << temUm (arvore->right) << std::endl;
    imprimir (arvore);
    arvore = pruneTree (arvore);
    imprimir (arvore);
} // main

