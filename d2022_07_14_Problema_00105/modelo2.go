/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

var indices map [int] int

func montar (preorder [] int, inorder [] int, proximo* int, esquerda int, direita int) *TreeNode {
    
    var retorno *TreeNode // = nil
    
    if esquerda <= direita {
        
        retorno = &TreeNode {Val: preorder [*proximo]}
        
        indiceAnt := indices [preorder [*proximo]]
        
        *proximo++
        
        retorno.Left = montar (preorder, inorder, proximo, esquerda, indiceAnt - 1)
        retorno.Right = montar (preorder, inorder, proximo, indiceAnt + 1, direita)
    }
    
    return retorno
}

func buildTree(preorder []int, inorder []int) *TreeNode {
    
    indices = make (map [int] int)
    
    for i, v := range inorder {
        indices [v] = i
    }
    
    var varredor int // = 0; para passar item a item no preorder
    
    return montar (preorder, inorder, &varredor, 0, len (preorder) - 1) // Para len, tanto fará
}

