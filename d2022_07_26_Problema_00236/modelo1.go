/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

var resposta *TreeNode

func auxiliar (no, p, q *TreeNode) bool {
    
    if no == nil {
        return false
    }
    // else
    
    var contagem int // = 0
    
    if no == q || no == p {
        contagem++
    }
    
    if auxiliar (no.Left, p, q) {
        contagem++
    }
    
    if auxiliar (no.Right, p, q) {
        contagem++
    }
    
    if contagem >= 2 { // Ou pegou o próprio nó e um dos descendentes ou dois descendentes
        resposta = no
    }
    
    return contagem >= 1 // Basta ter um para ser verdadeiro
    
}

func lowestCommonAncestor(root, p, q *TreeNode) *TreeNode {
    resposta = nil
    auxiliar (root, p, q)
    return resposta
}

