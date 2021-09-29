/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func splitListToParts(head *ListNode, k int) []*ListNode {
	var tmp [] int // Guardará os valores em um vetor
/*
Prepara tmp e as variáveis básicas para o algoritimo
*/
	for head != nil {
		tmp = append (tmp, head.Val)
		head = head.Next
	} // for head != nil
	tamanho := len (tmp)
	quociente := tamanho / k
	resto := tamanho % k
/*
Algoritmo propriamente dito
*/
	retorno := make ([] *ListNode, k)
	a := 0
	i := 0 // Em qual item está preenchendo
	var ultimo *ListNode // Para acompanhar o preenchimento de cada unidade
	for a < tamanho {
		adicional := 0
		if resto > 0 {
			adicional = 1
			resto--
		} // else if resto > 0
		j := 0
		for j < (quociente + adicional) { // Tenho certeza que a não enche aqui; matemática
			if retorno [i] == nil {
				retorno [i] = &ListNode {tmp [a], nil}
				ultimo = retorno [i]
			} else { // if retorno [i] == nil
				ultimo.Next = &ListNode {tmp [a], nil}
				ultimo = ultimo.Next
			} // else if retorno [i] == nil
			a++
			j++
		} // for j...
		i++ // Atenção para esse ponto!
	} // for a < tamanho
	return retorno
}

