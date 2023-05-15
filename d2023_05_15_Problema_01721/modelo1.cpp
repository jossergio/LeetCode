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
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        vector<ListNode*> lista;
        for (auto h = head; h != nullptr; h = h->next)
            lista.push_back (h);
        if (k <= lista.size ()) {
            int tmp = lista [k - 1]->val;
            lista [k - 1]->val = lista [lista.size () - k]->val;
            lista [lista.size () - k]->val = tmp;
        }
        return lista [0];
    }
};

