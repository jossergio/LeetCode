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
    vector<int> largestValues(TreeNode* root) {
        vector<int> resposta;
        queue<TreeNode*> fila;
        if (root != nullptr)
            fila.push (root);
        while (!fila.empty ()) {
            int maior = fila.front ()->val; // Pressupõe
            int t = fila.size ();
            while (t > 0) {
                maior = max (maior, fila.front ()->val);
                TreeNode* tmp = fila.front (); // Para facilitar visualizar o código
                fila.pop ();
                if (tmp->left != nullptr)
                    fila.push (tmp->left);
                if (tmp->right != nullptr)
                    fila.push (tmp->right);
                t -= 1;
            }
            resposta.push_back (maior);
        }
        return resposta;
    }
};

