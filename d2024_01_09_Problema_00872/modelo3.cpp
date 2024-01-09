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
    vector<int> buscar (TreeNode* no) {
        stack<TreeNode*> pilha;
        vector<int> folhas;
        pilha.push (no);
        while (!pilha.empty ()) {
            TreeNode* tmp = pilha.top ();
            pilha.pop ();
            if (tmp->left == nullptr && tmp->right == nullptr) // É folha
                folhas.push_back (tmp->val);
            else {
                if (tmp->left != nullptr)
                    pilha.push (tmp->left);
                if (tmp->right != nullptr)
                    pilha.push (tmp->right);
            }
        }
        return folhas;
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        return buscar (root1) == buscar (root2);
    }
};

