/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func profundidade (r *TreeNode, x int, y int, nivel int, nX *int, nY *int, pai *TreeNode, paiX **TreeNode, paiY **TreeNode) {
	if r == nil {
		return
	} // if r == nil
	nivel += 1
	if r.Val == x {
		*nX = nivel
		*paiX = pai
	} // if r.Val
	if r.Val == y {
		*nY = nivel
		*paiY = pai
	} // if r.Val == y
	if (*nX == 0) || (*nY == 0) {
		profundidade (r.Left, x, y, nivel, nX, nY, r, paiX, paiY)
		profundidade (r.Right, x, y, nivel, nX, nY, r, paiX, paiY)
	} // if nX == 0 || nY == 0
} // profundidade

func isCousins(root *TreeNode, x int, y int) bool {
	var nX, nY int = 0, 0
	var paiX, paiY *TreeNode = nil, nil
	var retorno bool = false
	if root != nil {
		profundidade (root.Left, x, y, 0, &nX, &nY, root, &paiX, &paiY)
		profundidade (root.Right, x, y, 0, &nX, &nY, root, &paiX, &paiY)
		retorno = (paiX != paiY) && (nX == nY)
	} // if root != nil
	return retorno
}

