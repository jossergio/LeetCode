class Solution {
public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root->val == p->val || root->val == q->val) // Se é um dos nós, então, é ele
      return root;
    if (p->val < q->val) // Os caras podem mandar dessa forma ou não
      if (root->val > p->val && root->val < q->val) // Se está no meio, é ele (ordem normal q < p)
          return root; // Idem
    if (p->val > q->val) // A outra forma que os caras podem mandar
      if (root->val > q->val && root->val < p->val) // Se está no meio, é ele (ordem inversa q > p)
        return root; // Idem
    if (root->val < p->val && root->val < q->val) // Está na direita
      return lowestCommonAncestor (root->right, p, q);
    else // Está na esquerda
      return lowestCommonAncestor (root->left, p, q);
    return NULL; // Para os casos que sobrarem
    } // lowestCommonAncestor
}; // class Solution

