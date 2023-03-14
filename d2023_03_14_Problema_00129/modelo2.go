/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

var acumuladoGeral int // = 0

func somar (no *TreeNode, acumuladoNivel int) {
	// Nunca vem o nil
	acumuladoNivel += no.Val
	if no.Left == nil && no.Right == nil {
		acumuladoGeral += acumuladoNivel
	} else { // if no.Left ...
		if no.Left != nil {
			somar (no.Left, acumuladoNivel * 10)
		} // if no.Left != nil
		if no.Right != nil {
			somar (no.Right, acumuladoNivel * 10)
		} // if no.Right != nil
	} // else if no.Left ...
} // somar

func sumNumbers(root *TreeNode) int {
	acumuladoGeral = 0
	if root != nil {
		somar (root, 0)
	}
	return acumuladoGeral
}

