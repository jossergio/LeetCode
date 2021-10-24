/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func contar (no *TreeNode, contador *int) {
	if no != nil {
		*contador++
		contar (no.Left, contador)
		contar (no.Right, contador)
	} // if root != nil
} // contar

func countNodes(root *TreeNode) int {
	var contador int // Por padrão, GoLang define zero
	if root != nil {
		contador++
		contar (root.Left, &contador)
		contar (root.Right, &contador)
	} // if root != nil
	return contador
}

