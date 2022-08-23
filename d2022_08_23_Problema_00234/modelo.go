/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func isPalindrome(head *ListNode) bool {
    
    var anterior *ListNode // = nil
    var novaLista *ListNode // = nil
    var tmp *ListNode = head
    
    for tmp != nil {
        novaLista = &ListNode {tmp.Val, anterior}
        anterior = novaLista
        tmp = tmp.Next
    }
    
    for head != nil {
        if head.Val != novaLista.Val {
            return false
        }
        head = head.Next
        novaLista = novaLista.Next
    }
    
    return true
}

