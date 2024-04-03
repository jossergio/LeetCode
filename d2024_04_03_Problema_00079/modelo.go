func montar (board [][] byte, word string, i int, j int, nivel int) bool {
    nivel += 1
    tmp := board [i][j]
    board [i][j] = '.' // Só para registrar que já passou por aqui
    if nivel == len (word) {
        return true // Se chegou até aqui é porque localizou; formou a palavra
    }
    // else
    if i - 1 >= 0 && board [i - 1][j] == word [nivel] && montar (board, word, i - 1, j, nivel) {
        return true
    }
    if i + 1 < len (board) && board [i + 1][j] == word [nivel] && montar (board, word, i + 1, j, nivel) {
        return true
    }
    if j - 1 >= 0 && board [i][j - 1] == word [nivel] && montar (board, word, i, j - 1, nivel) {
        return true
    }
    if j + 1 < len (board [0]) && board [i][j + 1] == word [nivel] && montar (board, word, i, j + 1, nivel) {
        return true
    }
    board [i][j] = tmp // Recompõe
    return false // Se não encontrou, chega aqui
}

func exist(board [][]byte, word string) bool {
    for i := 0; i < len (board); i++ {
        for j := 0; j < len (board [0]); j++ {
            if board [i][j] == word [0] && montar (board, word, i, j, 0) {
                return true
            }
        }
    }
    return false; // Checou tudo e não localizou
}

