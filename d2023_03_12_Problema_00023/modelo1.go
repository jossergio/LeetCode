/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func mergeKLists(lists []*ListNode) *ListNode {
    
    var resposta *ListNode // = nil
    var proximo *ListNode // = nil
    var sair bool // = false
    var tamanho int = len (lists)

    for !sair {
        var menor *ListNode = nil // Nenhum; definir valor, laço
        var indice int = -1 // Nenhum
        
        for i := 0; i < tamanho; i++ {
            if lists [i] != nil {
                if menor == nil || lists [i].Val < menor.Val {
                    menor = lists [i]
                    indice = i
                }
            }
        }
        
        if indice == -1 {
            sair = true
        } else {
            if resposta == nil {
                resposta = menor
                proximo = resposta
            } else {
                proximo.Next = menor
                proximo = proximo.Next
            }
            lists [indice] = lists [indice].Next
            proximo.Next = nil
        }
    }
    
    return resposta
}

