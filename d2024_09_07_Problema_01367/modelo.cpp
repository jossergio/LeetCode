/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool teste (ListNode* l, TreeNode* a) {
        if (a != nullptr) {
            if (l->val == a->val) {
                return l->next == nullptr || teste (l->next, a->left) || teste (l->next, a->right);
            } // Sem else
        }
        // else
        return false;
    }
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (root == nullptr) return false;
        // else
        return teste (head, root) || isSubPath (head, root->left) || isSubPath (head, root->right);
    }
};

