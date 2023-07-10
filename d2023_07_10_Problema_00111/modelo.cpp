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
    int minDepth(TreeNode* root) {
        int resposta {0};
        queue<TreeNode*> fila;
        if (root != nullptr)
            fila.push (root);
        while (!fila.empty ()) {
            resposta += 1;
            int t = fila.size ();
            while (t > 0) {
                t -= 1;
                TreeNode* item = fila.front ();
                fila.pop ();
                if (item->left == nullptr && item->right == nullptr)
                    return resposta;
                if (item->left != nullptr)
                    fila.push (item->left);
                if (item->right != nullptr)
                    fila.push (item->right);
            }
        }
        return 0; // Se chegou até aqui, é porque não encontrou
    }
};

