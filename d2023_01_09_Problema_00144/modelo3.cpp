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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> resposta;
        stack<TreeNode*> pilha;
        while (root) { // not nullptr
            resposta.push_back (root->val);
            pilha.push (root);
            root = root->left;
            if (!root) { // nullptr
                while (!pilha.empty ()) { // nullptr
                    TreeNode* tmp = pilha.top ();
                    pilha.pop ();
                    if (tmp->right) { // Melhor testar internamente que na condicional do laço
                        root = tmp->right;
                        break;
                    }
                }
            }
        }
        return resposta;
    }
};

