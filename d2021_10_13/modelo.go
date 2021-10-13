/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func inserir (n int, no *TreeNode) {
    // Nunca virá nil
    if n <= no.Val {
        if no.Left == nil {
            no.Left = &TreeNode {n, nil, nil}
        } else { // if n.Left == nil
            inserir (n, no.Left)
        } // else if n.Left == nil
    } else { // if n <= no.val
        if no.Right == nil {
            no.Right = &TreeNode {n, nil, nil}
        } else { // if n.right == nil
            inserir (n, no.Right)
        } // else if n.Rigt == nil
    }
} // inserir

func bstFromPreorder(preorder []int) *TreeNode {
    var raiz *TreeNode
    for _, i:= range preorder {
        if raiz != nil {
            inserir (i, raiz)
        } else { // if raiz != null
            raiz = &TreeNode {i, nil, nil}
        } // else if raiz != null
    } // for...
    return raiz
}

