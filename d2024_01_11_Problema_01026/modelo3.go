/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func fMaior (a int, b int) int {
    if (a > b) {
        return a
    }
    // else
    return b
}

func fMenor (a int, b int) int {
    if (a < b) {
        return a
    }
    // else
    return b
}

func fAbs (a int) int {
    if (a >= 0) {
        return a
    }
    // else
    return -a // Torna positivo
}

var maximo int

func maior_menor (no *TreeNode) (maior int, menor int) {
    maior = no.Val // Pressupõe
    menor = no.Val // Idem
    if no.Left != nil {
        tmpMaior, tmpMenor := maior_menor (no.Left);
        maximo = fMaior (maximo, fAbs (tmpMaior - no.Val))
        maximo = fMaior (maximo, fAbs (tmpMenor - no.Val))
        maior = fMaior (maior, tmpMaior)
        menor = fMenor (menor, tmpMenor)
    }
    if no.Right != nil {
        tmpMaior, tmpMenor := maior_menor (no.Right)
        maximo = fMaior (maximo, fAbs (tmpMaior - no.Val))
        maximo = fMaior (maximo, fAbs (tmpMenor - no.Val))
        maior = fMaior (maior, tmpMaior)
        menor = fMenor (menor, tmpMenor)
    }
    return // maior, menor
}
func maxAncestorDiff(root *TreeNode) int {
    maximo = 0
    maior_menor (root)
    return maximo // Que lógica louca
}

