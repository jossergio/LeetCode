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
} // type ListNode struct

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

/*
== Funções auxiliares e de visualização de resultados ==
*/

func verNumeros (l *ListNode) {
	if l != nil {
		fmt.Print (l.Val)
		verNumeros (l.Next)
	} else { // if l != nil
		fmt.Println ()
	} // else if l != nil
} // verNumeros

func mostrar (l1 *ListNode, l2 *ListNode) {
	var soma *ListNode = addTwoNumbers (l1, l2)
	fmt.Println ("Observar que a ordem dos algarismos é invertida!")
	fmt.Print ("Primeiro número: ")
	verNumeros (l1)
	fmt.Print ("Segundo número: ")
	verNumeros (l2)
	fmt.Print ("Soma: ")
	verNumeros (soma)
	fmt.Println ()
} // mostar

func main() {
	var l1 *ListNode = &ListNode {3, &ListNode {4, nil}} // 43
	var l2 *ListNode = &ListNode {5, &ListNode {2, nil}} // 25
	mostrar (l1, l2)
	l2 = &ListNode {1, &ListNode {2, &ListNode {3, nil}}} // 321
	mostrar (l1, l2)
}

