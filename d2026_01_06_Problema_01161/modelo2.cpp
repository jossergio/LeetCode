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
    void buscar (TreeNode* no, map<int, int>& mapa, int nivel) {
        if (no != nullptr) {
            mapa [nivel] += no->val;
            buscar (no->left, mapa, nivel + 1);
            buscar (no->right, mapa, nivel + 1);
        }
    }
public:
    int maxLevelSum(TreeNode* root) {
        map<int, int> mapa;
        buscar (root, mapa, 1); // root é nível 1
        int resposta = 1; // root
        int maior = mapa [1]; // De root
        for (auto m = mapa.begin (); m != mapa.end (); m++)
            if (m->second > maior) {
                maior = m->second;
                resposta = m->first;
            }
        return resposta;
    }
};
