/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func maior (a int, b int) int {
    if a > b {
        return a
    }
    // else
    return b
}

func buscar (no *TreeNode, nivel int, m map [int] int) {
    if no != nil {
        if _, existe := m [nivel]; existe {
            m [nivel] = maior (m [nivel], no.Val)
        } else {
            m [nivel] = no.Val
        }
        buscar (no.Left, nivel + 1, m)
        buscar (no.Right, nivel + 1, m)
    }
}

func largestValues(root *TreeNode) []int {
    tmp := make (map [int] int)
    buscar (root, 0, tmp)
    resposta := make ([] int, len (tmp))
    for i, v := range tmp {
        resposta [i] = v
    }
    return resposta
}

