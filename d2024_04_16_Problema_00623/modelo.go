/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func addOneRow(root *TreeNode, val int, depth int) *TreeNode {
    // Pela definição do problema, não vem nil
    if root == nil { // Só chega aqui porque não quiz fazer dois testes na chamada recursiva
        return nil;
    }
    // else
    if depth == 1 { // É a raiz
        return &TreeNode {val, root, nil}
    }
    // else
    if depth == 2 {
        root.Left = &TreeNode {val, root.Left, nil}
        root.Right = &TreeNode {val, nil, root.Right}
    } else { // Só pode ser maior que 2
        addOneRow (root.Left, val, depth - 1)
        addOneRow (root.Right, val, depth - 1)
    }
    return root
}

