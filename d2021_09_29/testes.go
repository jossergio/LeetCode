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

/*
Definição de estruturas, conforme definição do desafio
*/

type ListNode struct {
	Val int
	Next * ListNode
} // ListNode struct

/*
====
Função para o desafio
====
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

/*
====
Funções para testes
====
*/

func mostrar (head *ListNode, k int) {
	resultado := splitListToParts (head, k)
	for a := 0; a < len (resultado); a++ {
		tmp := resultado [a]
		fmt.Print ("Linha ", a, ": - ")
		for tmp != nil {
			fmt.Print (tmp.Val, " - ")
			tmp = tmp.Next
		} // for tmp != nil
		fmt.Println ()
	} // for a
	fmt.Println ()
} // mostra

func main() {
	mostrar (&ListNode {1, &ListNode {2, &ListNode {3, nil}}}, 5)
	mostrar (&ListNode {1,
		&ListNode {2,
		&ListNode {3,
		&ListNode {4,
		&ListNode {5,
		&ListNode {6,
		&ListNode {7,
		&ListNode {8,
		&ListNode {9,
		&ListNode {10,nil}}}}}}}}}}, 3)
}

