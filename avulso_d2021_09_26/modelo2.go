/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	var residual int = 0
	var retorno *ListNode // Inicialmente, nil
	var proximo *ListNode
	for l1 != nil || l2 != nil || residual != 0 {
		valor := residual // Começa o somatório de cada coluna de algarismos
		if l1 != nil {
			valor += l1.Val
			l1 = l1.Next
		} // if l1 != nil
		if l2 != nil {
			valor += l2.Val
			l2 = l2.Next
		} // if l2 != nil
		residual = valor % 10 // Aproveitar variável; deveria ser outra
		if (retorno == nil) {
			retorno = &ListNode {residual, nil}
			proximo = retorno
		} else { // if retorno == nil
			proximo.Next = &ListNode {residual, nil}
			proximo = proximo.Next
		} // else if retorno == nil
		residual = valor / 10
	} // for...
	return retorno
}

