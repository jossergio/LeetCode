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
    bool findTarget(TreeNode* root, int k) {
        
        vector<int> lista;
        stack<TreeNode*> pilha;
        
        TreeNode* atual = root;
        while (atual) {
            pilha.push (atual);
            atual = atual->left;
        }

        while (!pilha.empty ()) { // Irá varrer em em-ordem
            atual = pilha.top ();
            pilha.pop ();
            lista.push_back (atual->val);
            if (atual = atual->right)
                while (atual) {
                    pilha.push (atual);
                    atual = atual->left;
                }
        }

        // A lista já vem ordenada, pois é uma árvore de busca
        int i = 0, j = lista.size ()  - 1;
        while (i < j) {
            int v = lista [i] + lista [j];
            if (v == k)
                return true;
            if (v < k)
                i += 1;
            else
                j -= 1;
        }
        return false; // Por omissão, não localizou
    }
};

