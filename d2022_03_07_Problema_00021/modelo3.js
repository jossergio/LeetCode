/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} list1
 * @param {ListNode} list2
 * @return {ListNode}
 */
var mergeTwoLists = function(list1, list2) {
    let preResposta = {val: 0, next: null};
    let acompanhar = preResposta;
    while (list1 !== null || list2 !== null) {
        if (list1 === null) {
            acompanhar.next = list2;
            list2 = list2.next;
            acompanhar = acompanhar.next;
        } else {
            if (list2 === null) {
                acompanhar.next = list1;
                list1 = list1.next;
                acompanhar = acompanhar.next;
            } else {
                if (list1.val < list2.val) {
                    acompanhar.next = list1;
                    list1 = list1.next;
                    acompanhar = acompanhar.next;
                } else {
                    acompanhar.next = list2;
                    list2 = list2.next;
                    acompanhar = acompanhar.next;
                }
            }
        }
    }
    return preResposta.next;
};
