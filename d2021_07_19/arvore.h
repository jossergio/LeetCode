/*
  Cria a estrutura de uma árvores binária ordenada
*/

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode (int x): val (x), left (NULL), right (NULL) {};
}; // TreeNode

void incluir (TreeNode **no, int valor) {
  if (*no == NULL)
    *no = new TreeNode (valor);
  else // if no == NULL
    if (valor < (*no)->val)
      incluir (&(*no)->left, valor);
    else
      incluir (&(*no)->right, valor);
} // incluir

void ler (TreeNode *raiz) {
  if (raiz != NULL) {
    ler (raiz->left);
    std::cout << " " << raiz->val;
    ler (raiz->right);
  } // if raiz != NULL
} // ler

