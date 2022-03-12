/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

func somar (v1 int, v2 int, vem int) (s int, vai int) {
    s = v1 + v2 + vem
    vai = s / 10
    s %= 10
    return
}

func auxiliar (l1 *ListNode, l2 *ListNode, vemUm int) *ListNode {
    
    if l1 == nil && l2 == nil {
        if vemUm != 0 {
            return &ListNode {vemUm, nil}
        } else {
            return nil
        }
    }
    
    if l1 == nil {
        soma, vaiUm := somar (0, l2.Val, vemUm)
        return &ListNode {soma, auxiliar (nil, l2.Next, vaiUm)}
    } else {
        if l2 == nil {
            soma, vaiUm := somar (l1.Val, 0, vemUm)
            return &ListNode {soma, auxiliar (l1.Next, nil, vaiUm)}
        } else {
            soma, vaiUm := somar (l1.Val, l2.Val, vemUm)
            return &ListNode {soma, auxiliar (l1.Next, l2.Next, vaiUm)}
        }
    }
    
    return nil // Jamais chega aqui
}

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
    return auxiliar (l1, l2, 0)
}

