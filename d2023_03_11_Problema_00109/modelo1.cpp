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
    void inserir (int valor, TreeNode* no) {
        if (valor < no->val) {
            if (no->left) { // not nullptr
                inserir (valor, no->left);
            } else {
                no->left = new TreeNode (valor); // Folhas nullptr
            }
        } else {
            if (no->right) { // not nullptr
                inserir (valor, no->right);
            } else {
                no->right = new TreeNode (valor); // Folhas nulkptr
            }
        }
    }
    void processar (vector<int>& valores, TreeNode** arvore, int i, int j) {
        if (i > j)
            return; // Não há o que fazer nesse trecho
        // else
        int meio = (i + j) / 2;
        if (*arvore) // not nullptr
            inserir (valores [meio], *arvore);
        else
            *arvore = new TreeNode (valores [meio]); // É o primeiro; folhas nullptr
        processar (valores, arvore, i, meio - 1);
        processar (valores, arvore, meio + 1, j);
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> valores;
        while (head) { // not nullptr
            valores.push_back (head->val);
            head = head->next;
        }
        TreeNode* arvore = nullptr;
        processar (valores, &arvore, 0, valores.size () - 1);
        return arvore;
    }
};

