/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func sortList(head *ListNode) *ListNode {
    
    if head != nil {
        
        var anterior *ListNode = head
        
        for no := head.Next; no != nil; no = no.Next {
            if no.Val < head.Val {
                anterior.Next = no.Next
                no.Next = head
                head = no
            }
            anterior = no
        }
        head.Next = sortList (head.Next)
    }
    
    return head
}

