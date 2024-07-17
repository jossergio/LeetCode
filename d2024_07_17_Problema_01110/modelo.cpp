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
    TreeNode* remover (TreeNode* no, set<int>& lista, vector<TreeNode*>& resposta) {
        if (no->left != nullptr)
            no->left = remover (no->left, lista, resposta);
        if (no->right != nullptr)
            no->right = remover (no->right, lista, resposta);
        if (lista.count (no->val) > 0) {
            if (no->left != nullptr)
                resposta.push_back (no->left);
            if (no->right != nullptr)
                resposta.push_back (no->right);
            return nullptr;
        }
        // else
        return no;
    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        set<int> para_remover (to_delete.begin (), to_delete.end ()); // Para poder facilitar buscas
        vector<TreeNode*> resposta;
        if (remover (root, para_remover, resposta) != nullptr) {
            resposta.push_back (root);
        }
        return resposta;
    }
};

