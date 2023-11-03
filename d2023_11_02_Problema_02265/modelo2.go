/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func buscar (no *TreeNode, contar *int) (soma int64, divisor int) {
    if no == nil {
        return 0, 0
    }
    // else
    s1, d1 := buscar (no.Left, contar)
    s2, d2 := buscar (no.Right, contar)
    soma = int64 (no.Val) + s1 + s2
    divisor = 1 + d1 + d2
    if soma / int64 (divisor) == int64 (no.Val) {
        *contar += 1
    }
    return
}

func averageOfSubtree(root *TreeNode) int {
    var contar int // = 0
    buscar (root, &contar)
    return contar
}

