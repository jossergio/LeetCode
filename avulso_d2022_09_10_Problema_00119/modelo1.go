func getRow(rowIndex int) []int {
    
    triangulo := [][] int {{1}, {1, 1}} // Básico
    
    for i := 2; i <= rowIndex; i++ {
        
        linhaAnterior := i - 1 // Só para evitar ficar recalculando
        tmp := make ([] int, i + 1)
        
        tmp [0] = 1
        
        for j := 1; j < len (triangulo [linhaAnterior]); j++ {
            tmp [j] = triangulo [linhaAnterior][j - 1] + triangulo [linhaAnterior][j]
        }
        
        tmp [i] = 1 // Coindice com o tamanho do atual
        
        triangulo = append (triangulo, tmp)
    }
    
    return triangulo [rowIndex]
}

