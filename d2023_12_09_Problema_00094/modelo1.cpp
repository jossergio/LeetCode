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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> retorno;
        if (root == nullptr)
            return retorno; // Só para nao edentar o else
        stack<TreeNode*> pilha;
        TreeNode* no = root;
        while (no != nullptr) {
            pilha.push (no);
            no = no->left;
        }
        while (!pilha.empty ()) {
            TreeNode* tmp = pilha.top ();
            pilha.pop ();
            retorno.push_back (tmp->val);
            if (tmp->right != nullptr) {
                tmp = tmp->right;
                while (tmp != nullptr) {
                    pilha.push (tmp);
                    tmp = tmp->left;
                }
            }
        }
        return retorno;
    }
};

