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
        
        TreeNode* tmp;
        double soma;
        int contador;
        queue<TreeNode*> filaTemporaria;
        
        while (!fila.empty ()) {
            
            soma = 0; // Já 
            contador = 0;
            
            while (!fila.empty ()) {
                tmp = fila.front ();
                fila.pop ();
                soma += tmp->val;
                contador++;
                
                if (tmp->left)
                    filaTemporaria.push (tmp->left);
                
                if (tmp->right)
                    filaTemporaria.push (tmp->right);
            }
            
            resposta.push_back (soma / contador);
            
            while (!filaTemporaria.empty ()) {
                fila.push (filaTemporaria.front ());
                filaTemporaria.pop ();
            }
        }
        
        return resposta;
    }
};

