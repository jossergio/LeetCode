package main

import (
	"fmt"
)


/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Prev *Node
 *     Next *Node
 *     Child *Node
 * }
 */

type Node struct {
	Val int
	Prev *Node
	Next *Node
	Child *Node
} // Node struct

func pegarUltimo (filho *Node) *Node {
	no := filho
	for no.Next != nil { // filho nunca vem nil
		no = no.Next
	} // for no.Next != nil
	return no
}

func flatten(root *Node) *Node {
	no := root
	for no != nil {
		if no.Child != nil {
			filho := no.Child
			ultimo := pegarUltimo (filho)
			ultimo.Next = no.Next
			if no.Next != nil {
				proximo := no.Next
				proximo.Prev = ultimo
			} // if no.Next != nil
			no.Next = filho
			no.Child = nil
			filho.Prev = no
		} // if no.Child != nil
		no = no.Next
	} // for no != nil
	return root
}

func mostrarLista (inicio *Node) {
	no := inicio
	for no != nil {
		fmt.Print (" ", no.Val)
		no = no.Next
	} // for inicio |= nil
	fmt.Println ()
} // mostrarLista

func main() {
	var inicio *Node = &Node {1, nil, nil, &Node {2, nil, nil, nil}}
	inicio.Next = &Node {3, inicio, nil, nil}
	mostrarLista (inicio)
	inicio = flatten (inicio)
	mostrarLista (inicio)
}

