/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

func inserir (inicio, fim, no *ListNode) (inicial, final *ListNode) {
// Só para dividir trabalho e organizar código
    inicial = inicio // Para, também, garantir o retorno dessa variável
    if inicial == nil { // 1o elemento
        final = no
        inicial = final
    } else { // if inicial == nil
        final = fim;
        final.Next = no
        final = final.Next
    } // else if inicial == nil
    return // As variáveis de retorno já foram definidas
} // inserir

func oddEvenList(head *ListNode) *ListNode {
    var contador int // Inicia em zero
    var inicioImpar, inicioPar, fimImpar, fimPar *ListNode // nil é padrão
    for head != nil {
        contador++
        if contador % 2 == 1 {
            inicioImpar, fimImpar = inserir (inicioImpar, fimImpar, head)
        } else { //
            inicioPar, fimPar = inserir (inicioPar, fimPar, head)
        } //
        head = head.Next
    } // for head != nil
    if fimPar != nil { // LeetCode pode fornecer uma lista vazia ou de elemento único
        fimPar.Next = nil
    } //
    if fimImpar != nil { // Idem
        fimImpar.Next = inicioPar
    } //
    return inicioImpar
}

