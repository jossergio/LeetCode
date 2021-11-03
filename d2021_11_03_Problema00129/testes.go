package main

import (
	"fmt"
)

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

type TreeNode struct {
	Val int
	Left *TreeNode
	Right *TreeNode
} // TreeNode struct

func somar (no *TreeNode, acumuladoNivel int, acumuladoGeral *int) {
	// Nunca vem o nil
	acumuladoNivel += no.Val
	if no.Left == nil && no.Right == nil {
		*acumuladoGeral += acumuladoNivel
	} else { // if no.Left ...
		if no.Left != nil {
			somar (no.Left, acumuladoNivel * 10, acumuladoGeral)
		} // if no.Left != nil
		if no.Right != nil {
			somar (no.Right, acumuladoNivel * 10, acumuladoGeral)
		} // if no.Right != nil
	} // else if no.Left ...
} // somar

func sumNumbers(root *TreeNode) int {
	var somatorio int = 0
	if root != nil {
		somar (root, 0, &somatorio)
	}
	return somatorio
}

func main() {
	var arvore *TreeNode = &TreeNode {1, nil, nil}
	fmt.Println (sumNumbers (arvore))

	arvore = &TreeNode {1, &TreeNode {2, nil, nil}, nil}
	fmt.Println (sumNumbers (arvore))

	arvore = &TreeNode {1, &TreeNode {2, nil, nil}, &TreeNode {3, nil, nil}}
	fmt.Println (sumNumbers (arvore))

	arvore = &TreeNode {4, &TreeNode {9, &TreeNode {5, nil, nil}, &TreeNode {1, nil, nil}}, &TreeNode {0, nil, nil}}
	fmt.Println (sumNumbers (arvore))
}

