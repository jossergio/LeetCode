/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val   int
 *     Left  *TreeNode
 *     Right *TreeNode
 * }
 */

func lowestCommonAncestor(root, p, q *TreeNode) *TreeNode {
    
    if root.Val == p.Val || root.Val == q.Val { // Se é um dos dois, então, é ele
        return root
    }
    
    if p.Val < q.Val { // A plataforma pode mandar assim
        if (root.Val > p.Val && root.Val < q.Val) { // Se está no meio, é ele (ordem normal q < q)
            return root
        }
    }
    
    if p.Val > q.Val { // A outra forma que a plataforma pode mandar
        if root.Val > q.Val && root.Val < p.Val { // Se está no meio, é ele (ordem inversa q > p)
            return root
        }
    }
    
    if (root.Val < p.Val && root.Val < q.Val) { // Está na direita
        return lowestCommonAncestor (root.Right, p, q)
    } else {
        return lowestCommonAncestor (root.Left, p, q)
    }
    
    return nil // Para o caso de chegar aqui. Não chega.
}

