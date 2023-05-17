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
    int pairSum(ListNode* head) {
        vector<int> twins;
        while (head != nullptr) {
            twins.push_back (head->val);
            head = head->next;
        }
        int t = twins.size ();
        int maximo = 0;
        for (int i = 0; i < t / 2; i += 1)
            maximo = max (maximo, twins [i] + twins [t - i - 1]);
        return maximo;
    }
};

