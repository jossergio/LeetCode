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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> fila;
        fila.push (root); // Há, pelo menos, um, pelo problema
        int resposta;
        while (!fila.empty ()) {
            resposta = fila.front ()->val;
            int t = fila.size ();
            while (t > 0) {
                TreeNode* tmp = fila.front ();
                fila.pop ();
                if (tmp->left != nullptr)
                    fila.push (tmp->left);
                if (tmp->right != nullptr)
                    fila.push (tmp->right);
                t -= 1;
            }
        }
        return resposta;
    }
};

