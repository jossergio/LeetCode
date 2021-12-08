/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func encontrar (no *TreeNode) (tilt int, soma int) {
    if no != nil {
        tiltEsq, somaEsquerda := encontrar (no.Left)
        tiltDir, somaDireita := encontrar (no.Right)
        tilt = int (math.Abs (float64 (somaEsquerda - somaDireita))) + tiltEsq + tiltDir
        soma = no.Val + somaEsquerda + somaDireita
    }
    return // Os valores já estão definidos
} // encontrar

func findTilt(root *TreeNode) int {
    var resposta int
    resposta, _ = encontrar (root)
    return resposta
}

