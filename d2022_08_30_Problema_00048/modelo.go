func rotate(matrix [][]int)  {
    
    tamanho := len (matrix)
    metade := len (matrix) / 2
        
    for i := 0; i < tamanho; i++ {
        for j := i + 1; j < tamanho; j++ {
            matrix [j][i], matrix [i][j] = matrix [i][j], matrix [j][i]
        }
    }
    
    for i := 0; i < len (matrix); i++ {
        for j := 0; j < metade; j++ {
            matrix [i][j], matrix [i][tamanho - 1 - j] = matrix [i][tamanho - 1 - j], matrix [i][j]
        }
    }
    // return
}

