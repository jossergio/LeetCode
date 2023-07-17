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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> n1;
        stack<int> n2;
        while (l1 != nullptr) {
            n1.push (l1->val);
            l1 = l1->next;
        }
        while (l2 != nullptr) {
            n2.push (l2->val);
            l2 = l2->next;
        }
        ListNode* resposta = nullptr;
        int vaiUm = 0;
        while (!(n1.empty () && n2.empty ())) {
            int i1 = 0, i2 = 0;
            if (!n1.empty ()) {
                i1 = n1.top ();
                n1.pop ();
            }
            if (!n2.empty ()) {
                i2 = n2.top ();
                n2.pop ();
            }
            ListNode* tmp = new ListNode {((i1 + i2 + vaiUm) % 10), resposta};
            resposta = tmp;
            vaiUm = (i1 + i2 + vaiUm) / 10;
        }
        while (vaiUm > 0) {
            ListNode* tmp = new ListNode {(vaiUm % 10), resposta};
            resposta = tmp;
            vaiUm /= 10;
            }
        return resposta;
    }
};

