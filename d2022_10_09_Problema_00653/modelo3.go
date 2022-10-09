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
    var lista [] int
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
        lista = append (lista, atual.Val)
        atual = atual.Right
        for atual != nil {
            tmp := &No {atual, pilha}
            pilha = tmp
            atual = atual.Left
        }
    }

   // A árvore é uma árvore de busca e, por isso, uma leitora em-ordem é ordenada
   var i, j int = 0, len (lista) - 1
   for i < j {
       v := lista [i] + lista [j]
       if (v == k) {
           return true
       }
       if (v < k) {
           i += 1
       } else {
           j -= 1
       }
   }

   return false // Por omissão, caso não encontre
}

