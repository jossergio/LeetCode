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
    int maxProfundo (TreeNode *no, int *maior, int *menor) {
        if (no == nullptr)
            return 0;
        int iMaior = no->val, iMenor = no->val; // Internos; valores iniciais para referência
        int tmp1 = maxProfundo  (no->left, &iMaior, &iMenor);
        if (iMaior > *maior) *maior = iMaior;
        if (iMenor < *menor) *menor = iMenor;
        int tmp2 = maxProfundo (no->right, &iMaior, &iMenor);
        if (iMaior > *maior) *maior = iMaior;
        if (iMenor < *menor) *menor = iMenor;
        if (tmp2 > tmp1) tmp1 = tmp2;
        tmp2 = abs (no->val -iMaior);
        if (tmp2 > tmp1) tmp1 = tmp2;
        tmp2 = abs (no->val - iMenor);
        if (tmp2 > tmp1) tmp1 = tmp2;
        return tmp1;
    } // maxProfundo
public:
    int maxAncestorDiff(TreeNode* root) {
        // Não refatorei
        if (root == nullptr)
            return 0;
        int maior = root->val, menor = root->val;
        int resposta1 = maxProfundo (root->left, &maior, &menor);
        int resposta2 = maxProfundo (root->right, &maior, &menor);
        if (resposta2 > resposta1) resposta1 = resposta2;
        resposta2 = abs (root->val - maior);
        if (resposta2 > resposta1) resposta1 = resposta2;
        resposta2 = abs (root->val - menor);
        if (resposta2 > resposta1) resposta1 = resposta2;
        return resposta1;
    }
};

