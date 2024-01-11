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
    int maximo = 0;
    vector<int> lado (TreeNode* no) {
        vector<int> retorno;
        if (no->left != nullptr) {
            vector<int> esquerdo = lado (no->left);
            sort (esquerdo.begin (), esquerdo.end ());
            maximo = max (maximo, abs (esquerdo [0] - no->val));
            maximo = max (maximo, abs (esquerdo [esquerdo.size () - 1] - no->val));
            retorno.insert (retorno.end (), esquerdo.begin (), esquerdo.end ());
        }
        if (no->right != nullptr) {
            vector<int> direito = lado (no->right);
            sort (direito.begin (), direito.end ());
            maximo = max (maximo, abs (direito [0] - no->val));
            maximo = max (maximo, abs (direito [direito.size () - 1] - no->val));
            retorno.insert (retorno.end (), direito.begin (), direito.end ());
        }
        retorno.push_back (no->val);
        return retorno;
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        vector<int> tmp = lado (root);
        return maximo; // Que lógica louca
    }
};

