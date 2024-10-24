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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        // Os três primeiros testes implicam ser a raiz de todos
        if (root1 == nullptr && root2 == nullptr) return true;
        // else
        if ((root1 == nullptr && root2 != nullptr) || (root1 != nullptr && root2 == nullptr)) return false; // Implica que ambos são não nulos
        // else]
        if (root1->val != root2->val) return false;
        // else
        if (root1->left == nullptr && root1->right == nullptr && root2->left == nullptr && root2->right == nullptr) return true; // Não pode haver nada abaixo, aqui
        if (root1->left != nullptr && root2->left != nullptr && root1->right != nullptr && root2->right != nullptr) {
            if (root1->left->val == root2->left->val && root1->right->val == root2->right->val)
                return flipEquiv (root1->left, root2->left) && flipEquiv (root1->right, root2->right);
            // else
            if (root1->left->val == root2->right->val && root1->right->val == root2->left->val)
                return flipEquiv (root1->left, root2->right) && flipEquiv (root1->right, root2->left);
            return false; // Idem acima
        }
        // else
        if (root1->left == nullptr && root2->left == nullptr) {
            return (root1->right != nullptr && root2->right != nullptr && root1->right->val == root2->right->val) &&
                flipEquiv (root1->right, root2->right);
        }
        // else
        if (root1->left == nullptr && root2->right == nullptr) {
            return (root1->right != nullptr && root2->left != nullptr && root1->right->val == root2->left->val) &&
                flipEquiv (root1->right, root2->left);
        }
        // else
        if (root1->right == nullptr && root2->left == nullptr) {
            return (root1->left != nullptr && root2->right != nullptr && root1->left->val == root2->right->val) &&
                flipEquiv (root1->left, root2->right);
        }
        // else
        if (root1->right == nullptr && root2->right == nullptr) {
            return (root1->left != nullptr && root2->left != nullptr && root1->left->val == root2->left->val) &&
                flipEquiv (root1->left, root2->left);
        }
        // else
        return false; // Só para ter algo aqui
    }
};

