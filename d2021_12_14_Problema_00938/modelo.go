/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func rangeSumBST(root *TreeNode, low int, high int) int {
    var resposta int = 0
    if root != nil { // Garantir o 1o, pois os demais serão testados antes
        if root.Val >= low && root.Val <= high {
            resposta = root.Val
        }
        if root.Left != nil && root.Val > low {
            resposta += rangeSumBST (root.Left, low, high)
        }
        if root.Right != nil && root.Val < high {
            resposta += rangeSumBST (root.Right, low, high)
        }
    }
    return resposta
}

