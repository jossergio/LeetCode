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
protected:
    void buscar (TreeNode* no, int objetivo, vector<vector<int>>& resposta, vector<int>& tmp, int soma) {
        
        tmp.push_back (no->val); // Nunca deve chegar nullptr aqui; iniciar testes na funçao principal para evitar testar sempre na recursão
        soma += no->val;
        
        if (!(no->left) && !(no->right)) {
            if (soma == objetivo)
                resposta.push_back (tmp);
        } else { // if no left && no right
            if (no->left)
                buscar (no->left, objetivo, resposta, tmp, soma);

            if (no->right)
                buscar (no->right, objetivo, resposta, tmp, soma);
        }
        
        tmp.pop_back ();
        // soma se desfafz sozinha, pois e por valor
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        vector<vector<int>> resposta;
        vector<int> temporario;
        
        if (root)
            buscar (root, targetSum, resposta, temporario, 0);
        
        return resposta;
    } // pathSum
}; // Class Solution

