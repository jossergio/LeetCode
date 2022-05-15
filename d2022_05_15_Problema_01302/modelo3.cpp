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
    int soma;
    int maisBaixo;
    
    void somar (TreeNode* no, int nivel) {
        
        if (no == nullptr)
            return;
        
        if ((no->left == nullptr) && (no->right == nullptr)) // É uma folha
            if (nivel > maisBaixo) {
                maisBaixo = nivel;
                soma = no->val; // Recomeça a contagem
            } else {
                if (nivel == maisBaixo)
                    soma += no->val;
            }
        else {
            somar (no->left, nivel + 1);
            somar (no->right, nivel + 1);
        }
    }
    
public:
    int deepestLeavesSum(TreeNode* root) {
        
        soma = 0;
        maisBaixo = 0;
        
        somar (root, 0);
        return soma;
    }
};

