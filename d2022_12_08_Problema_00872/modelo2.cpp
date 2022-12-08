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
    vector<int> pegarFolhas (TreeNode* raiz) {
        vector<int> folhas;
        stack<TreeNode*> pilha;
        pilha.push (raiz);
        while (!pilha.empty ()) {
            TreeNode* trabalhar = pilha.top ();
            pilha.pop ();
            if (trabalhar->right || trabalhar->left) {
                if (trabalhar->right)
                    pilha.push (trabalhar->right); // Ficará para depois
                if (trabalhar->left)
                    pilha.push (trabalhar->left); // Ficará no topo
            } else { // É folha
                folhas.push_back (trabalhar->val);
            }
        }
        return folhas;
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> folhas1 = pegarFolhas (root1); // Traz só os valores
        vector<int> folhas2 = pegarFolhas (root2); // Idem
        return folhas1 == folhas2;
    }
};

