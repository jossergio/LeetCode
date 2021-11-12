/*
Desafio LeetCode em 12/11/2021. Problema 203.

Remover elementos em uma lista ligada.
*/

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
	Next * ListNode
} // type ListNode struct

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

func mostrar (lista *ListNode) {
	correr := lista
	for correr != nil {
		fmt.Print (correr.Val, " ")
		correr = correr.Next
	} // for correr != nil
	fmt.Println ()
} // mostrar

func main() {
	lista := &ListNode {1, &ListNode {2, &ListNode {6, &ListNode {3, &ListNode {4,
		&ListNode {5, &ListNode {6, nil}}}}}}}
	fmt.Println ("Antes:")
	mostrar (lista)
	removeElements (lista, 6)
	fmt.Println ("Depois de tirar o 6:")
	mostrar (lista)
}

