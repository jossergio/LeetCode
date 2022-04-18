/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

var cabeca, fim *TreeNode

func incluir (valor int) {
    
    tmp := &TreeNode {valor, nil, nil}
    
    if cabeca == nil {
        cabeca = tmp
        fim = cabeca
    } else {
        fim.Right = tmp
        fim = fim.Right
    }
}

func varrer (raiz *TreeNode) {
    if raiz != nil {
        varrer (raiz.Left)
        incluir (raiz.Val)
        varrer (raiz.Right)
    }
}

func increasingBST(root *TreeNode) *TreeNode {
    
    cabeca, fim = nil, nil
    
    varrer (root)
    
    return cabeca
}

