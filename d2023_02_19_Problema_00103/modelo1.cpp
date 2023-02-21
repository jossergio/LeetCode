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
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> resposta;
        deque<TreeNode*> auxiliar; // Irá fazer o zigzag
        int sentido = 0; // Próximo sentido; 0 é o nível par; 1 é o nível ímpar
        TreeNode* tmp; // Só para definir fora do laço, evitar perder tempo alocando
        int t; // Idem
        if (root)
            auxiliar.push_back (root);
        while (!auxiliar.empty ()) {
            vector<int> linha;
            t = auxiliar.size ();
            if (sentido) { // Nivel ímpar, sentido esquerda-direita
                while (t) { // Maior que zero; not zero
                    tmp = auxiliar.back ();
                    auxiliar.pop_back ();
                    linha.push_back (tmp->val);
                    if (tmp->right)
                        auxiliar.push_front (tmp->right);
                    if (tmp->left)
                        auxiliar.push_front (tmp->left);
                    t -= 1;
                }
            } else { // Nível par, sentido direita-esquerda
                while (t) {
                    tmp = auxiliar.front ();
                    auxiliar.pop_front ();
                    linha.push_back (tmp->val);
                    if (tmp->left)
                        auxiliar.push_back (tmp->left);
                    if (tmp->right)
                        auxiliar.push_back (tmp->right);
                    t -= 1;
                }
            }
            if (linha.size ()) // > 0
                resposta.push_back (linha);
            sentido = 1 - sentido; // Passa para o próximo sentido
        }
        return resposta;
    }
};

