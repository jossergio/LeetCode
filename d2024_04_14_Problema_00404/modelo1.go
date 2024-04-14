/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func somarFolhasEsquerdas (no *TreeNode, somatorio *int) {
	if no.Left != nil {
		filho := no.Left
		if filho.Left == nil && filho.Right == nil { // Olha só, o filho esquerdo é folha
			*somatorio += filho.Val
		} else { // if filho.Left ...
			somarFolhasEsquerdas (filho, somatorio)
		} // else if filho.Left
	}
	if no.Right != nil { // Não precisa tratar o nó direito. Passa direto.
		somarFolhasEsquerdas (no.Right, somatorio)
	} // if no.Right != niol
} // somarFolhasEsquerdas

func sumOfLeftLeaves(root *TreeNode) int {
	var somatorio int = 0
	if root != nil { // Só para não ir nil
		somarFolhasEsquerdas (root, &somatorio)
	}
	return somatorio
}

