func isValidSudoku(board [][]byte) bool {
    valoresBloco := make ([] map [byte] bool, 9)
    for a := 0; a < 9; a++ {
        valoresBloco [a] = make (map [byte] bool)
    }
    for i := 0; i < 9; i++ {
        valoresH := make (map [byte] bool)
        valoresV := make (map [byte] bool)
        for j := 0; j < 9; j++ {
            if board [i][j] != '.' {
                if _, existe := valoresH [board [i][j]]; existe {
                    return false;
                } else {
                    valoresH [board [i][j]] = true
                }
                if _, existe := valoresBloco [3 * (i / 3) + (j / 3)][board [i][j]]; existe {
                    return false
                } else {
                    valoresBloco [3 * (i / 3) + (j / 3)][board [i][j]] = true
                }
            }
            if board [j][i] != '.' {
                if _, existe := valoresV [board [j][i]]; existe {
                    return false
                } else {
                    valoresV [board [j][i]] = true
                }
            }
        }
    }
    return true
}
