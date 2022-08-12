/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val   int
 *     Left  *TreeNode
 *     Right *TreeNode
 * }
 */

func lowestCommonAncestor(root, p, q *TreeNode) *TreeNode {
    
    for root != nil {
        if p.Val < root.Val && q.Val < root.Val { // Está na esquerda
            root = root.Left
        } else {
            if p.Val > root.Val && q.Val > root.Val { // Está na direita
                root = root.Right
            } else { // Está entre os dois, ou seja, é o próprio
                return root
            }
        }
    }
    
    return nil // Só para constar. Não deve chegar aqui
}

