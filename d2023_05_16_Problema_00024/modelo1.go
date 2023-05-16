/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func swapPairs(head *ListNode) *ListNode {
    if head != nil && head.Next != nil {
        seguinte := head.Next
        head.Next = swapPairs (seguinte.Next)
        seguinte.Next = head
        return seguinte
    }
    // else
    return head
}

