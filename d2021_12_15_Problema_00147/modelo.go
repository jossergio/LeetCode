/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func insertionSortList(head *ListNode) *ListNode {
    if head == nil {
        return nil
    }
    anterior := head
    for proximo := head.Next; proximo != nil; anterior, proximo = proximo, proximo.Next {
        if proximo.Val < anterior.Val {
            anterior.Next = proximo.Next
            temp := proximo
            proximo = anterior // Só para regular com o laço
            if temp.Val < head.Val {
                temp.Next = head
                head = temp
            } else {
                tmpAnterior := head
                lugar := head.Next // Precisarei, ao final do laço
                for lugar.Val < temp.Val {
                    tmpAnterior, lugar = lugar, lugar.Next
                }
                tmpAnterior.Next = temp
                temp.Next = lugar
            }
        }
    }
    return head
}

