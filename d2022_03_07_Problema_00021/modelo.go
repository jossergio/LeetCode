/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

func adicionar (item *ListNode, ultimo *ListNode, cabeca *ListNode) (i, u, c *ListNode) {
    if ultimo == nil { // Início da lista
        u = item
        c = item
    } else {
        u = ultimo
        u.Next = item
        u = u.Next
        c = cabeca // Só para gonstar
    }
    i = item.Next
    return // i, u, c
}

func mergeTwoLists(list1 *ListNode, list2 *ListNode) *ListNode {
    
    if list1 == nil {
        return list2 // LeetCode
    }
    
    if list2 == nil {// Mais LeetCide
        return list1
    }
    // As condições acima também evitam um pequeno probleminha no if depois do laço.
    // Ou de ter que fazer ajustes com mais ifs.
    // Além disso, agilizam nesses casos e no geral
    
    
    var resposta, ultimo *ListNode // = nil
    
    for list1 != nil && list2 != nil {
        if list1.Val < list2.Val {
            list1, ultimo, resposta = adicionar (list1, ultimo, resposta)
        } else {
            list2, ultimo, resposta = adicionar (list2, ultimo, resposta)
        }
    }
    
    if list1 == nil {
        ultimo.Next = list2
    } else {
        ultimo.Next = list1
    }
    
    return resposta
}

