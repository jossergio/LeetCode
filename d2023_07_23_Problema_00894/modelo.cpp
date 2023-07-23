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
    unordered_map<int, vector<TreeNode*>> niveis;
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        if (n %2 == 0) // Inclui as impossibilidades; tem que ser ímpar
            return {};
        if (n == 1)
            return {new TreeNode {}}; // Na criação, val = 0
        if (niveis.find (n) != niveis.end ()) // Já criou esse nível
            return niveis [n];
        vector<TreeNode*> resposta;
        for (int i = 1; i < n; i += 2) { // A raiz não conta
            vector<TreeNode*> esquerdas = allPossibleFBT (i); // Todas as árvores da esquerda com esse número
            vector<TreeNode*> direitas = allPossibleFBT (n - i - 1); // Todas as árvores da direita com esse número; e balanceia com o restante de i
            for (auto esquerda: esquerdas)
                for (auto direita: direitas)
                    resposta.push_back (new TreeNode (0, esquerda, direita));
        } // for i
        return niveis [n] = resposta; // Atualiza o memorizador, criando novo nível
    }
};

