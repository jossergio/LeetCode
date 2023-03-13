/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func produzir (valores [] int) *TreeNode {
    if len (valores) == 0 { // Nada a fazer aqui
        return nil
    }
    meio := len (valores) / 2
    retorno := &TreeNode {valores [meio], nil, nil} // Folhas vazias
    if meio > 0 {
        retorno.Left = produzir (valores [0:meio]) // O último não entra
    }
    if meio < len (valores) {
        retorno.Right = produzir (valores [meio + 1:len (valores)])
    }
    return retorno
}

func sortedListToBST(head *ListNode) *TreeNode {
    var valores [] int
    for head != nil {
        valores = append (valores, head.Val)
        head = head.Next
    }
    return produzir (valores)
}

