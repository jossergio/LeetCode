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
    bool hasPathSumAcumulador (TreeNode *root, int targetSum, int acumulador) {
        bool retorno = false;
        acumulador += root->val; // Veja que é por valor
// Obs.: nunca vem nullptr
        if (root->left == nullptr && root->right == nullptr && acumulador == targetSum)
            return true; // Chegou em uma folha e o valor tá com o objetivo
        if (root->left != nullptr)
            if (retorno = hasPathSumAcumulador (root->left, targetSum, acumulador))
                return true; // Já encontrou
        if (root->right != nullptr)
            retorno = hasPathSumAcumulador (root->right, targetSum, acumulador);
        return retorno; // Passando ou não, vem com um resultado
    } // hasPathSumAcumulador
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool retorno = false;
        if (root != nullptr) {
            if (root->left == nullptr && root->right == nullptr && root->val == targetSum)
                return true; // A raiz é única e já é o valor
            if (root->left != nullptr)
                if (retorno = hasPathSumAcumulador (root->left, targetSum, root->val))
                    return true; // Já encontrou
            if (root->right != nullptr)
                retorno = hasPathSumAcumulador (root->right, targetSum, root->val);
            // Não precisa testar retorno. Final dos testes. Já vai retornar seu valor.
        } // if root != nulptr
        return retorno; // Passando ou não, vem com um resultado
    }
};

