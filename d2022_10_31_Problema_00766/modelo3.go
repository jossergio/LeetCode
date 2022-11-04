func isToeplitzMatrix(matrix [][]int) bool {
    elementos := make (map [int] int)
    for i, linha := range matrix {
        for j, elemento := range linha {
            valor, existe := elementos [j - i]
            if existe {
                if elemento != valor {
                    return false
                }
            } else {
                elementos [j - i] = elemento
            }
        }
    }
    return true // Por omissão, se chegou até aqui
}

