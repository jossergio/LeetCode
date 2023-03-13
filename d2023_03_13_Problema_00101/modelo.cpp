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
    bool isSymmetric(TreeNode* root) {
        deque<TreeNode*> fila; // Percorrera cada nível da árvore
        // dqueue permite acessar elementos individualmente
        bool tem = false;
        if (root) { // not nullptr
            fila.push_back (root);
            tem = true;
        }
        while (tem) {
            tem = false;
            int t = fila.size ();
            int i; // Para os laços
            for (i = 0; i < t / 2; i += 1) {
                if (fila [i] == nullptr xor fila [t - i - 1] == nullptr)
                    return false;
                // else
                if (fila [i] == nullptr && fila [t - i - 1] == nullptr)
                    continue;
                // else
                if (fila [i]->val != fila [t - i - 1]->val)
                    return false;
                }
            for (i = 0; i < t; i += 1) {
                TreeNode* tmp = fila.front ();
                fila.pop_front ();
                if (tmp == nullptr) { // Irá jogar as folhar imaginárias
                    fila.push_back (nullptr);
                    fila.push_back (nullptr);
                } else {
                    fila.push_back (tmp->left);
                    fila.push_back (tmp->right);
                    tem = true;
                }
            }
        }
        return true; // Por omissão, se passou em todos os testes e chegou até aqui
    }
};

