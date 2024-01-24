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
bool podeSer (const vector<int>& numeros) {
    int impares = 0;
    for (int i = 0; i <= 9; i += 1) {
        if (numeros [i] % 2 == 1) {
            impares += 1;
            if (impares > 1)
                return false; // Não pode se transformar em palíndromo
        }
    }
    return true; // Passou
} // podeSer

void buscar (TreeNode* no, vector<int>& acumulados, int& contador) {
    acumulados [no->val] += 1;
    if (no->left == nullptr && no->right == nullptr) {
        if (podeSer (acumulados))
            contador += 1;
    } else {
        if (no->left != nullptr)
            buscar (no->left, acumulados, contador);
        if (no->right != nullptr)
            buscar (no->right, acumulados, contador);
    }
    acumulados [no->val] -= 1;
}

public:
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> acumulados {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; // 10 posições
        int contador = 0;
        buscar (root, acumulados, contador);
        return contador;
    }
};

