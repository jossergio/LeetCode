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
        
        vector<int> v;
        ListNode *h; // Irei reaproveitar a variável
        
        for (h = head; h != nullptr; h = h->next)
            v.push_back (h->val);
        
        if (k <= v.size ()) {
            int tmp = v [k - 1];
            v [k - 1] = v [v.size () - k];
            v [v.size () - k] = tmp;
        }
        
        // h já vem nullptr
        
        for (vector<int>::reverse_iterator i = v.rbegin (); i != v.rend (); i++) {
            ListNode *n = new ListNode (*i, h);
            h = n;
        }
        
        return h;
    }
};

