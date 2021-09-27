package main

import (
	"fmt"
	"math"
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

/*
== Funções do algoritmo
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

func converterLista (n int) *ListNode {
	var resto int = n % 10
	n /= 10
	var retorno *ListNode = &ListNode {resto, nil}
	var penultimo = retorno // Para ir adicionando ao final
	for n > 0 {
		resto = n % 10
		penultimo.Next = &ListNode {resto, nil}
		penultimo = penultimo.Next
		n /= 10
	} // for  > 0
	return retorno
} // converterLista

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	var soma int = pegarValor (l1) + pegarValor (l2)
	return converterLista (soma)
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
	fmt.Println ("Valor do primeiro número: ", pegarValor (l1))
	fmt.Println ("Valor do segundo número: ", pegarValor (l2))
	fmt.Print ("Soma: ")
	verNumeros (soma)
	fmt.Println ()
} // mostar

func main() {
	var l1 *ListNode = converterLista (43)
	var l2 *ListNode = converterLista (21)
	mostrar (l1, l2)
	l2 = converterLista (321)
	mostrar (l1, l2)
	l1 = converterLista (1000000000000000000000000000001)
	l2 = converterLista (465)
	mostrar (l1, l2)
}

