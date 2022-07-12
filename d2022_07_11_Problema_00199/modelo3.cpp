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
    vector<int> rightSideView(TreeNode* root) {
        
        vector<int> resposta;
        queue<TreeNode*> acompanhar; // Para acompanhar os subníveis
        
        if (root == nullptr) // Nada a fazer e evita adicionar nulo na lista de trabalho
            return resposta; // Ainda vazia
        
        acompanhar.push (root); // Inicia
        
        while (!acompanhar.empty ()) {
            
            resposta.push_back (acompanhar.front ()->val);
            
            // Inicia o processo de recomposição de acompanhar
            int qtd = acompanhar.size (); // Ira rotacionar a fila qtd vezes
            for (int i = 0; i < qtd; i++) {
                TreeNode* tmp = acompanhar.front ();
                acompanhar.pop ();
                if (tmp->right != nullptr)
                    acompanhar.push (tmp->right);
                if (tmp->left != nullptr)
                    acompanhar.push (tmp->left);
            }
        }
        
        return resposta;
    }
};

