/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func swapPairs(head *ListNode) *ListNode {

    if head == nil {
        return nil
    }
    
    if head.Next != nil {
        seguinte := head.Next
        tmp := seguinte.Next
        head.Next = swapPairs (tmp)
        seguinte.Next = head
        return seguinte
    } else {
        return head
    }
    
}

