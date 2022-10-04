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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root) { // Só não é na primeira passada; as demais, o teste é no ramo antes de chamar a função
            targetSum -= root->val;
            if (!(root->left) && !(root->right)) { // É uma folha
                if (targetSum == 0)
                    return true;
                // Nada mais a fazer
            } else {
                return (hasPathSum (root->left, targetSum) || hasPathSum (root->right, targetSum));
                // targetSum já está atualizado, aqui
            }

        }
        return false; // Por omissão
    }
};

