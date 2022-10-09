/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
 type No struct {
    Item *TreeNode
    Proximo *No
}
func findTarget(root *TreeNode, k int) bool {
    valores := make (map [int] bool) // bool é só para ter um tipo
    var pilha *No // = nil

    var atual *TreeNode = root
    for atual != nil {
        tmp := &No {Item: atual, Proximo: pilha}
        pilha = tmp
        atual = atual.Left
    }

    for pilha != nil {
        atual = pilha.Item
        pilha = pilha.Proximo

        if _, existe := valores [k - atual.Val]; existe { // Se o complemento existe (já está nos valores), a questão é verdadeira
            return true
        }
        // else
        valores [atual.Val] = true // Só para fazer constar o valor atual no mapa de valores
        
        atual = atual.Right
        for atual != nil {
            tmp := &No {atual, pilha}
            pilha = tmp
            atual = atual.Left
        }
    }

    return false // Por omissão, caso não encontre
}

