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
    vector<int> lista;
    int contar = 0;
    
    bool verificar (int v) {
        for (int a = 0; a < lista.size (); a++)
            if (lista [a] > v)
                return false;
        return true;
    } // verificar
    
    void procurar (TreeNode *root) {
        if (verificar (root->val))
            contar++;
        lista.push_back (root->val);
        if (root->left != nullptr)
            procurar (root->left);
        if (root->right != nullptr)
            procurar (root->right);
        lista.pop_back ();
    } // procurar
public:
    int goodNodes(TreeNode* root) {
        if (root != nullptr)
            procurar (root);
        return contar;
    }
};

