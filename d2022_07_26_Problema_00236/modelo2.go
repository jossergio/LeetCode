/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func lowestCommonAncestor(root, p, q *TreeNode) *TreeNode {
    if root == nil {
        return nil
    }
    // else
    
    if root == p || root == q {
        // Qualquer um que vier depois daqui terá esse como comum
        return root
    }
    
    esquerdo := lowestCommonAncestor (root.Left, p, q)
    direito := lowestCommonAncestor (root.Right, p, q)
    
    if esquerdo == nil && direito == nil {
        return nil
    }
    
    if esquerdo == nil { // Com certeza, direito não é nil e é a resposta
        return direito
    }
    
    if direito == nil {
        return esquerdo
    }
    
    return root // É ancestral pelos dois lados, direito e esquerdo não são nil
}

