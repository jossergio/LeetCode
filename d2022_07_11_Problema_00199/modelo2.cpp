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
        vector<TreeNode*> acompanhar; // Para acompanhar os subníveis
        stack<TreeNode*> pilha; // Para auxiliar a recompor acompanhar
        
        if (root == nullptr) // Nada a fazer e evita adicionar nulo na lista de trabalho
            return resposta; // Ainda vazia
        
        acompanhar.push_back (root); // Inicia
        
        while (!acompanhar.empty ()) {
            
            resposta.push_back (acompanhar.back ()->val);
            
            // Inicia o processo de recomposição de acompanhar
            pilha.push (acompanhar.back ()); // O primeiro a ser recomposto
            acompanhar.pop_back (); // Retira
            while (!acompanhar.empty ()) {
                pilha.push (acompanhar.back ());
                acompanhar.pop_back ();
            }
            
            // Faz a recomposição
            while (!pilha.empty ()) {
                TreeNode* tmp = pilha.top (); // Variável temporária para diminuir código
                if (tmp->left != nullptr)
                    acompanhar.push_back (tmp->left);
                if (tmp->right != nullptr)
                    acompanhar.push_back (tmp->right);
                pilha.pop ();
            }
        }
        
        return resposta;
    }
};

