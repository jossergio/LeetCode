/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func deleteDuplicates(head *ListNode) *ListNode {
    
    if head != nil {
        anterior := head
        proximo := head.Next
        for proximo != nil {
            if proximo.Val == anterior.Val {
                anterior.Next = proximo.Next
            } else {
                anterior = proximo
            }
            proximo = proximo.Next
        }
    }
    
    return head
}

