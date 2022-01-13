/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func soma (no *TreeNode, subtotal int) int {
    if no != nil {
        subtotal <<= 1
        subtotal += no.Val
        if no.Left == nil && no.Right == nil {
            return subtotal
        } else {
            return soma (no.Left, subtotal) + soma (no.Right, subtotal)
        }
    }
    return 0 // Só se a Árvore for vazia
}

func sumRootToLeaf(root *TreeNode) int {
    return soma (root, 0)
}

