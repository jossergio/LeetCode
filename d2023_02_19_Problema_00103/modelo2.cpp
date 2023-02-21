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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> resposta;
        queue<TreeNode*> fila;
        if (root)
            fila.push (root);
        int sentido = 0; // Proximo sentido; 0 par;  ímpar
        int t; // Para evitar ficar alocando dentro do laço
        TreeNode* tmp; // Idem
        while (!fila.empty ()) {
            t = fila.size ();
            vector<int> linha (t);
            for (int i = 0; i < t; i += 1) {
                tmp = fila.front ();
                fila.pop ();
                linha [sentido? i: t - 1 - i] = tmp->val;
                if (tmp->right)
                    fila.push (tmp->right);
                if (tmp->left)
                    fila.push (tmp->left);
            }
            resposta.push_back (linha);
            sentido = 1 - sentido; // Inverte
        }
        return resposta;
    }
};

