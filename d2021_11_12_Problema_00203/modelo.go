/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func removeElements(head *ListNode, val int) *ListNode {
	var anterior *ListNode // GoLang joga nil por padrão
	var correr *ListNode = head
	for correr != nil {
		if correr.Val == val {
		// Anterior não muda nessa situação
			if anterior != nil {
				anterior.Next = correr.Next
			} else { // if anterior != nil
				head = head.Next
			} // else if anterior != nil
		} else { // if correr.Val == val
			anterior = correr
		} // else if correr.Val == val
		correr = correr.Next
	} // for correr != nil
	return head
}

