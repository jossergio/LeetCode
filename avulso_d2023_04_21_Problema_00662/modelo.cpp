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

typedef pair<unsigned long long int, TreeNode*> MeuPar;

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<MeuPar> fila;
        fila.push ({1, root}); // O problema diz que sempre haverá o root
        int resposta = 1; // O próprio root
        // Variáveis definidas aqui, para evitar tempo de alocação no laço
        unsigned long long int inicio, fim;
        MeuPar tmp;
        int tamanho;
        while (!fila.empty ()) {
            tamanho = fila.size ();
            inicio = -1;
            fim = -1;
            for (int i = 0; i < tamanho; i += 1) {
                tmp = fila.front ();
                fila.pop ();
                if (tmp.second->left) {
                    unsigned long long int k = tmp.first * 2 - 1;
                    if (inicio == -1)
                        inicio = k;
                    fim = k;
                    fila.push ({k, tmp.second->left});
                }
                if (tmp.second->right) {
                    unsigned long long int k = tmp.first * 2;
                    if (inicio == -1)
                        inicio = k;
                    fim = k;
                    fila.push ({k, tmp.second->right});
                }
            }
            resposta = max (resposta, (int) (inicio == -1 ? : fim - inicio + 1));
        }
        return resposta;
    }
};

