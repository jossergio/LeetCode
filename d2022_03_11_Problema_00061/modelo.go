/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func rotateRight(head *ListNode, k int) *ListNode {
    
    var vetorNos [] *ListNode
    
    for h := head; h != nil; h = h.Next {
        vetorNos = append (vetorNos, h)
    }
    
    var tamanho int = len (vetorNos) // Serác usado várias vezes
    
    if tamanho < 2 { // Indifere de k
        return head
    }
    
    for k >= tamanho {
        k -= tamanho
    }
    
    if k != 0 {
        head = vetorNos [tamanho - k]
        vetorNos [tamanho - k - 1].Next = nil
        vetorNos [tamanho - 1].Next = vetorNos [0]
    }
    
    return head
}

