/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func buscaBinaria (lista [] int, elemento int, inicio int, fim int) int { // Retorna -1 se não encontrar
    
    var base int = -1 // Por padrão, não encontrou
    
    if inicio <= fim {
        base = (inicio + fim) / 2
        if lista [base] != elemento {
            tmp := buscaBinaria (lista, elemento, inicio, base - 1)
            if tmp == -1 {
                base = buscaBinaria (lista, elemento, base + 1, fim)
            } else {
                base = tmp
            }
        }
    }
    
    return base // Se encontrou, contém o índice; caso não, conterá -1
}

func montar (preorder [] int, inorder [] int, proximo* int, esquerda int, direita int) *TreeNode {
    
    var retorno *TreeNode // = nil
    
    if esquerda <= direita {
        indice := buscaBinaria (inorder, preorder [*proximo], esquerda, direita)
        if indice != -1 {
            retorno = &TreeNode {Val: preorder [*proximo]}
            *proximo++
            retorno.Left = montar (preorder, inorder, proximo, esquerda, indice - 1)
            retorno.Right = montar (preorder, inorder, proximo, indice + 1, direita)
        }
    }
    
    return retorno
}


func buildTree(preorder []int, inorder []int) *TreeNode {
    
    var varredor int // = 0; para passar item a item no preorder
    
    return montar (preorder, inorder, &varredor, 0, len (preorder) - 1) // Para len, tanto fará
}
