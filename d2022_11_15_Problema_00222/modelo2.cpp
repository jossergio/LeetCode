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
    int countNodes(TreeNode* root) {
        if (!root) // nullptr
            return 0;
        int contar = 0;
        stack<TreeNode*> pilha;
        pilha.push (root);
        while (!pilha.empty ()) {
            TreeNode* atual = pilha.top ();
            while (atual->left) { // not nullptr
                pilha.push (atual->left);
                atual = atual->left;
            }
            contar += 1;
            pilha.pop (); // É o próprio atual
            while (!pilha.empty () && !atual->right) {
                contar += 1;
                atual = pilha.top ();
                pilha.pop ();
            }
            if (atual->right)
                pilha.push (atual->right);
        }
        return contar;
    }
};

