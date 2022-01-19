/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

var lista [] *ListNode

func existe (no *ListNode) *ListNode{
    for _, n := range (lista) {
        if no == n {
            return n
        }
    }
    return nil
}

func detectCycle(head *ListNode) *ListNode {
    var resposta *ListNode
    for head != nil {
        resposta = existe (head.Next)
        if resposta != nil {
            return resposta
        }
        lista = append (lista, head)
        head = head.Next
    }
    return resposta // Sempre será nil, aqui
}

