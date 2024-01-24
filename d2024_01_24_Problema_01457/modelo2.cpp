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
    vector<int> acumulados {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; // 10 posições
    int contador {0};

    bool podeSer () {
        int impares = 0;
        for (int i = 0; i <= 9; i += 1) {
            if (acumulados [i] % 2 == 1) {
                impares += 1;
                if (impares > 1)
                    return false; // Não pode se transformar em palíndromo
            }
        }
        return true; // Passou
    } // podeSer

    void buscar (TreeNode* no) {
        acumulados [no->val] += 1;
        if (no->left == nullptr && no->right == nullptr) {
            if (podeSer ())
                contador += 1;
        } else {
            if (no->left != nullptr)
                buscar (no->left);
            if (no->right != nullptr)
                buscar (no->right);
        }
        acumulados [no->val] -= 1;
    }

public:
    int pseudoPalindromicPaths (TreeNode* root) {
        buscar (root);
        return contador;
    }
};

