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
    bool isPalindrome(ListNode* head) {
        vector<int> teste;
        while (head != nullptr) {
            teste.push_back (head->val);
            head = head->next;
        }
        const int t = teste.size ();
        for (int i = 0; i < t / 2; i += 1)
            if (teste [i] != teste [t - 1 - i])
                return false;
        return true; // Passou por tudo e não falhou
    }
};

