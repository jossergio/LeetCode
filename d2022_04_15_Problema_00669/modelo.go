/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func trimBST(root *TreeNode, low int, high int) *TreeNode {
    // Não farei limpeza de memória
    // Além disso, GoLang faz
    
    if root == nil {
        return nil
    }
    
    if root.Val < low {
        return trimBST (root.Right, low, high)
    }
    
    if root.Val > high {
            return trimBST (root.Left, low, high)
        }
    
    root.Left = trimBST (root.Left, low, high)
    root.Right = trimBST (root.Right, low, high)
    
    return root
}

