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
    vector<double> averageOfLevels(TreeNode* root) {
        
        vector<double> resposta;
        
        queue<TreeNode*> fila;
        
        fila.push (root); // O prolema cita que sempre há, pelo menos, um nó
        
        while (!fila.empty ()) {
            
            double soma = 0; // Já 
            int contador = 0;
            int tamanhoAtual = fila.size (); // Irá tirar esses elementos enquanto acrescenta outros
            
            for (int i = 0; i < tamanhoAtual; i++) {
                TreeNode* tmp = fila.front ();
                fila.pop ();
                soma += tmp->val;
                contador++;
                
                if (tmp->left)
                    fila.push (tmp->left);
                
                if (tmp->right)
                    fila.push (tmp->right);
            }
            
            resposta.push_back (soma / contador);
        }
        
        return resposta;
    }
};

