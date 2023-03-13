/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func mergeKLists(lists []*ListNode) *ListNode {
    aux := &ListNode {}
    proximo := aux
    for true {
        var menor int // = 0
        var indice int = -1 // Para referência
        for i := 0; i < len (lists); i += 1 {
            if lists [i] != nil && (indice == -1 || lists [i].Val < menor) {
                menor = lists [i].Val
                indice = i
            }
        }
        if indice == -1 { // Não tem nais na lista
            break // for true
        }
        proximo.Next = lists [indice]
        lists [indice] = lists [indice].Next
        proximo = proximo.Next
        proximo.Next = nil
    }
    return aux.Next
}

