package main

import (
	"fmt"
)

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

type ListNode struct {
	Val int
	Next *ListNode
} // ListNode struct

func incluir (lista **ListNode, ultimo **ListNode, valor int) {
	var tmp *ListNode = *ultimo
	if *lista == nil {
		*lista = &ListNode {valor, nil}
		*ultimo = *lista
	} else { // if lista == nil
		tmp.Next = &ListNode {valor, nil}
		tmp = tmp.Next
		*ultimo = tmp
	} // else if lista == nil
} // incluir

func mergeTwoLists(l1 *ListNode, l2 *ListNode) *ListNode {
	var retorno, ultimo *ListNode = nil, nil
	switch {
		case l1 == nil: return l2 // Incluindo se for nil, também
		case l2 == nil: return l1 // Idem
	} // switch
	for l1 != nil && l2 != nil {
		if l1.Val == l2.Val {
			incluir (&retorno, &ultimo, l1.Val)
			l1 = l1.Next
			incluir (&retorno, &ultimo, l2.Val)
			l2 = l2.Next
		} else { // if l1.Val == l2.Val
			if l1.Val < l2.Val {
				incluir (&retorno, &ultimo, l1.Val)
				l1 = l1.Next
			} else { // if l1.Val < l2.Val
				incluir (&retorno, &ultimo, l2.Val) // Só pode ser ele
				l2 = l2.Next
			} // else if l1.Val < l2.Val
		} // else if l1.Val == l2.Val
	} // for l1 != nil && l2 != nil
	switch {
		case l1 == nil: ultimo.Next = l2 // Independente de ser nil
		case l2 == nil: ultimo.Next = l1 // Idem
	} // swith
	return retorno
}

func mostrarLista (lista *ListNode) {
	for lista != nil {
		fmt.Print (lista.Val, " ")
		lista = lista.Next
	} // for lista != nil
} // mostrarLista

func mostrar (l1 *ListNode, l2 *ListNode) {
	fmt.Print ("Lista 1: ")
	mostrarLista (l1)
	fmt.Println ()
	fmt.Print ("Lista 2: ")
	mostrarLista (l2)
	fmt.Println ()
	fmt.Print ("Juntada: ")
	mostrarLista (mergeTwoLists (l1, l2))
	fmt.Println ()
} // mostrar

func main() {
	var lista1 *ListNode = &ListNode {1, &ListNode {3, &ListNode {4, nil}}}
	var lista2 *ListNode = &ListNode {1, &ListNode {2, &ListNode {4, nil}}}
	mostrar (lista1, lista2)

	lista1 = &ListNode {1, &ListNode {3, &ListNode {4, &ListNode {5, nil}}}}
	lista2 = &ListNode {1, &ListNode {2, &ListNode {4, nil}}}
	mostrar (lista1, lista2)

	lista1 = &ListNode {1, nil}
	lista2 = &ListNode {1, &ListNode {2, &ListNode {4, nil}}}
	mostrar (lista1, lista2)
}

