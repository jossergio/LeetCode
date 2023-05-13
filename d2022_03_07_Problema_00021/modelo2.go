/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func mergeTwoLists(list1 *ListNode, list2 *ListNode) *ListNode {
    var preResposta *ListNode = &ListNode {0, nil}
    var acompanhar *ListNode = preResposta
    for list1 != nil || list2 != nil {
        if list1 == nil {
            acompanhar.Next = list2
            list2 = list2.Next
            acompanhar = acompanhar.Next
        } else {
            if list2 == nil {
                acompanhar.Next = list1
                list1 = list1.Next
                acompanhar = acompanhar.Next
            } else {
                if list1.Val < list2.Val {
                    acompanhar.Next = list1
                    list1 = list1.Next
                    acompanhar = acompanhar.Next
                } else {
                    acompanhar.Next = list2
                    list2 = list2.Next
                    acompanhar = acompanhar.Next
                }
            }
        }
    }
    return preResposta.Next
}

