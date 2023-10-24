/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

var resposta [] int

func maior (a int, b int) int {
    if a > b {
        return a
    }
    // else
    return b
}

func buscar (no *TreeNode, nivel int) {
    if no != nil {
        if nivel < len (resposta) {
            resposta [nivel] = maior (resposta [nivel], no.Val)
        } else { // Só pode ser uma unidade maior
            resposta = append (resposta, no.Val)
        }
        buscar (no.Left, nivel + 1)
        buscar (no.Right, nivel + 1)
    }
}

func largestValues(root *TreeNode) []int {
    resposta = [] int {}
    buscar (root, 0)
    return resposta
}

