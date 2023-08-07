func procuraBinaria (vetor [] int, objetivo int) bool {
    
    var i, f int = 0, len (vetor) - 1
    
    for i <= f {
        
        meio := (i + f) / 2
        
        if vetor [meio] == objetivo {
            return true
        }
        
        if objetivo < vetor [meio] {
            f = meio - 1
        } else {
            i = meio + 1
        }
        
    }
    
    return false // Se chegou até aqui é porque não encontrou
}


func searchMatrix(matrix [][]int, target int) bool {
    
    var ultimo int = len (matrix [0]) - 1 // Último item de cada linha
    
    var i, f int = 0, len (matrix) - 1
    
    for i <= f {
        
        meio := (i + f) / 2
        
        if target >= matrix [meio][0] && target <= matrix [meio][ultimo] {
            return procuraBinaria (matrix [meio], target)
        }
        
        if target < matrix [meio][0] {
            f = meio - 1
        } else { // Só pode ser maior que o último elemento da linha
            i = meio + 1
        }
    }
    
    return false // Se chegou até aqui, não encontrou
}

