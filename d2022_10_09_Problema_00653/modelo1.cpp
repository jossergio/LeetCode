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
        queue<TreeNode*> fila;
        
        fila.push (root); // root nunca é nullptr
        while (!fila.empty ()) { // Irá varrer em pré-ordem
            TreeNode* atual = fila.front ();
            fila.pop ();
            lista.push_back (atual->val);
            if (atual->left)
                fila.push (atual->left);
            if (atual->right)
                fila.push (atual->right);
        }

        sort (lista.begin (), lista.end ());

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

