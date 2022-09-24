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
    vector<vector<int>> resultado;
    vector<int> temporario;
    int objetivo = 0;

    void buscar (TreeNode *root);
    int soma ();
    
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        objetivo = targetSum;
        if (root != nullptr)
            buscar (root);
        return resultado;
    } // pathSum
}; // Class Solution

void Solution::buscar (TreeNode *root) {
    temporario.push_back (root->val);
    if (root->left == nullptr && root->right == nullptr) {
        if (soma () == objetivo) {
            resultado.push_back (temporario);
        }
    } else {
        if (root->left != nullptr) {
            buscar (root->left);
        }
        if (root->right != nullptr) {
            buscar (root->right);
        }
    }
    temporario.pop_back ();
} // Solution::buscar

int Solution::soma () {
    int retorno = 0;
    for (int a = 0; a < temporario.size (); a++)
        retorno += temporario [a];
    return retorno;
} // Solution::soma

