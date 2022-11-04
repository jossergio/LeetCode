func isToeplitzMatrix(matrix [][]int) bool {
    for coluna := 0; coluna < len (matrix [0]); coluna++ {
        comp := matrix [0][coluna]
        linha := 1
        col := coluna + 1
        for linha < len (matrix) && col < len (matrix [0]) {
            if matrix [linha][col] != comp {
                return false
            }
            col += 1
            linha += 1
        }
    }
    for linha := 1; linha < len (matrix); linha++ {
        comp := matrix [linha][0]
        coluna := 1
        lin := linha + 1
        for lin < len (matrix) && coluna < len (matrix [0]) {
            if matrix [lin][coluna] != comp {
                return false
            }
            lin += 1
            coluna += 1
        }
    }
    return true // Por omissão, se chegou até aqui
}

