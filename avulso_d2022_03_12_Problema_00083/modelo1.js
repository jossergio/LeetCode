/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var deleteDuplicates = function(head) {
    if (head !== null) {
        let ant = head;
        let prox = head.next;
        while (prox !== null) {
            if (ant.val === prox.val) {
                ant.next = prox.next;
            } else {
                ant = prox;
            }
            prox = prox.next;
        }
    }
    return head;
};
