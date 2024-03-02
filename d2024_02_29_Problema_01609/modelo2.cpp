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
private:
    bool teste (TreeNode* a, bool par, queue<TreeNode*>& f) {
        if ((a->val % 2 == 0) != par)
            return false;
        if (a->left != nullptr)
            f.push (a->left);
        if (a->right != nullptr)
            f.push (a->right);
        return true; 
    }
    bool teste (TreeNode* a, TreeNode* p, bool par, queue<TreeNode*>& f) {
        if (!teste (p, par, f))
            return false;
        if (a->val == p->val || (a->val > p->val) != par)
            return false;
        return true;
    }
public:
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> fila;
        bool par = false; // A prineira linha é ímpar; será usada para ambas
        fila.push (root); // Semore há um, pela definição do problema
        while (!fila.empty ()) {
            int t = fila.size ();
            TreeNode* atual = fila.front ();
            fila.pop ();
            t -= 1; // A cada pop na fila
            if (!teste (atual, par, fila))
                return false;
            while (t > 0) {
                TreeNode* proximo = fila.front ();
                fila.pop ();
                t -= 1;
                if (!teste (atual, proximo, par, fila))
                    return false;
                atual = proximo;
            }
            par = !par; // Inverte
        }
        return true; // Passou por tudo
    }
};

