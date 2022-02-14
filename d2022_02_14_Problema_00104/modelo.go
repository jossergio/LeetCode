/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func maximo (a, b int) int {
    
    if a > b {
        return a
    }
    
    return b
}

func auxiliar (root *TreeNode, nivelAtual int) int {
    
    if root == nil {
        return nivelAtual
    }
    
    nivelAtual++
    
    return maximo (auxiliar (root.Left, nivelAtual), auxiliar (root.Right, nivelAtual))
}

func maxDepth(root *TreeNode) int {
    return auxiliar (root, 0)
}

