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
    void montarLista (TreeNode *r) {
        if (r != nullptr) {
            lista.push_back (r->val);
            montarLista (r->left);
            montarLista (r->right);
        } // if r != nullptr
    } // montarLista
public:
    bool findTarget(TreeNode* root, int k) {
        montarLista (root);
        cout << lista.size () << endl;
        if (lista.size () < 1)
            return false;
        unsigned a, b;
        for (a = 0; a < lista.size () - 1; a++)
            for (b = (a + 1); b < lista.size (); b++)
                if ((lista [a] + lista [b]) == k)
                    return true;
        return false;
    } // findTarger
}; // class Solution

