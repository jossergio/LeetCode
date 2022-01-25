func validMountainArray(arr []int) bool {
    var tamanho int = len (arr)
    
    if tamanho < 3{
        return false
    }
    
    if arr [0] >= arr [1] {
        return false // O Algoritmo exigiu esse teste, para o 1o
    }
    
    var i int = 1 // Começa do segundo
    
    for i < tamanho && arr [i - 1] < arr [i] {
        i++
    }
    
    if i == tamanho || arr [i - 1] == arr [i] { // Pensemos...
        return false
    }
    
    for i < tamanho && arr [i - 1] > arr [i] {
        i++
    }
    
    return i == tamanho // Tem lógica
    // Por essa lógica, não precisa saber se é menor ou igual
}

