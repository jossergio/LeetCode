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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        // Pelo problema, sempre haveró um nós, mas, o algoritimo cria situações para isso
        if (!root) // É nulo; era isso ou fazer dois destes na recursividade
            return nullptr;
        if (depth == 1) // É a raiz
            return new TreeNode (val, root, nullptr);
        if (depth == 2) { // Tá chegando perto
            root->left = new TreeNode (val, root->left, nullptr);
            root->right = new TreeNode (val, nullptr, root->right);
        } else { // Só pode ser maior que 2
            // Os testes para ver se não será nullptr serão feitos na chamada da função
            addOneRow (root->left, val, depth - 1);
            addOneRow (root->right, val, depth - 1);
        }
        return root;
    }
};

