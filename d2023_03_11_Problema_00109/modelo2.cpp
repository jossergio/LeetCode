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
    TreeNode* produzir (vector<int>& valores, int i, int j) {
        if (i > j) // Não há nais o que se fazer nesse trecho
            return nullptr;
        // else
        int meio = (i + j) / 2;
        return new TreeNode (valores [meio], produzir (valores, i, meio - 1), produzir (valores, meio + 1, j)); // Numa linha, tudo
        
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> valores;
        while (head) { // not nullptr
            valores.push_back (head->val);
            head = head->next;
        }
        return produzir (valores, 0, valores.size () - 1);
    }
};

