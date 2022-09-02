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
    void proceder (TreeNode* no, int nivel, vector<double>& somas, vector<int>& conts) {
        
        if (!no)
            return;
        
        if (nivel < somas.size ()) { // Já vinha resgistrando esse nível anteriormente; atualizar valores
            somas [nivel] += no->val;
            conts [nivel]++;
        } else { // Deverá adicionar um  nível; obs.: 0-begin; com certeza, nivel == somas.size ()
            somas.push_back (no->val);
            conts.push_back (1); // 1o elemento; até aqui, só conterá um
        }
        
        if (no->left)
            proceder (no->left, nivel + 1, somas, conts);
        
        if (no->right)
            proceder (no->right, nivel + 1, somas, conts);
    }
    
public:
    vector<double> averageOfLevels(TreeNode* root) {
        
        vector<double> resposta;
        vector<int> contadores;
        
        proceder (root, 0, resposta, contadores);
        
        for (int i = 0; i < resposta.size (); i++) // Fará a média; até aqui, resposta só tinha a soma
            resposta [i] /= contadores [i]; // Possuem o mesmo tamanho
        
        return resposta;
    }
};

