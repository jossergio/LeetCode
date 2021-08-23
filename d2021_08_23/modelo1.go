/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

var lista [] int

func montarLista (r *TreeNode) {
	if (r != nil) {
		lista = append (lista, r.Val)
		montarLista (r.Left)
		montarLista (r.Right)
	} // if r != nil
} // montarLista

func findTarget(root *TreeNode, k int) bool {
    lista = nil
    montarLista (root)
	var a, b int
	for a = 0; a < len (lista) - 1; a++ {
		for b = a + 1; b < len (lista); b++ {
			if ((lista [a] + lista [b]) == k) {
				return true
			} // if ...
		} // for b
	} // for a
	return false
}

