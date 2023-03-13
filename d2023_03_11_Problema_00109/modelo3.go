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

func produzir (valores [] int, i int, j int) *TreeNode {
    if i > j { // Nada a fazer aqui
        return nil
    }
    // else
    meio := (i + j) / 2
    return &TreeNode {valores [meio], produzir (valores, i, meio - 1), produzir (valores, meio + 1, j)} // Tudo em uma linha
}

func sortedListToBST(head *ListNode) *TreeNode {
    var valores [] int
    for head != nil {
        valores = append (valores, head.Val)
        head = head.Next
    }
    return produzir (valores, 0, len (valores) - 1)
}

