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
    
    var ultimo int = len (matrix [0]) - 1 // Último elemento em cada linha
    
    for i := 0; i < len (matrix); i++ {
        if target >= matrix [i][0] && target <= matrix [i][ultimo] {
            return procuraBinaria (matrix [i], target)
        }
    }
    
    return false // Se chegou até aqui, não encontrou
}

