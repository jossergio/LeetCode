func isToeplitzMatrix(matrix [][]int) bool {
    // Observar que inicia da segunda linha e segunda coluna; 0-begin
    for i := 1; i < len (matrix); i++ {
        for j := 1; j < len (matrix [0]); j++ {
            if matrix [i][j] != matrix [i - 1][j - 1] {
                return false
            }
        }
    }
    return true // Por omissão, se chegou até aqui
}

