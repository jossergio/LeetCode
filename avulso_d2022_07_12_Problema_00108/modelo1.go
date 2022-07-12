/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func montar (nums [] int, esq int, dir int) *TreeNode {
    
    var resposta *TreeNode // = nil
    
    if esq <= dir {
        base := (dir + esq) / 2
        resposta = &TreeNode {nums [base], nil, nil}
        if ! (esq == dir) { // Ou seja, menor
            resposta.Left = montar (nums, esq, base - 1)
            resposta.Right = montar (nums, base + 1, dir)
        }
    }
    
    return resposta
}

func sortedArrayToBST(nums []int) *TreeNode {
    return montar (nums, 0, len (nums) - 1) // O problema cita que nunca vem vazio
}

