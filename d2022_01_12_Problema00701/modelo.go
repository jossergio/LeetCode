/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func insertIntoBST(root *TreeNode, val int) *TreeNode {
    if root == nil {
        return &TreeNode {val, nil, nil}
    } else { // if root == nil
        if root.Val > val {
            root.Left = insertIntoBST (root.Left, val)
        } else { // if root > val
            root.Right = insertIntoBST (root.Right, val)
        } // else if root > val
    } // else if root == nil
    // O problema garante que não há valores iguais
    return root
}

