/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

func pegarValorEfetivo (l * ListNode, sequencial int) (valor int) {
	if l != nil {
		valor = pegarValorEfetivo (l.Next, sequencial + 1)
		valor += l.Val * int (math.Pow10 (sequencial)) // Adiciona o que já tem
	} else { // if l != nil
		valor = 0
	} // else if l != nil
	return // Já tem o valor definido
} // pegarValorEfetivo

func pegarValor (l *ListNode) (valor int) {
	return pegarValorEfetivo (l, 0)
} // 

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	var soma int = pegarValor (l1) + pegarValor (l2)
	var resto int = soma % 10
	soma /= 10
	var retorno *ListNode = &ListNode {resto, nil}
	var penultimo = retorno // Para ir adicionando ao final
	for soma > 0 {
		resto = soma % 10
		penultimo.Next = &ListNode {resto, nil}
		penultimo = penultimo.Next
		soma /= 10
	} // for soma > 0
	return retorno
}

