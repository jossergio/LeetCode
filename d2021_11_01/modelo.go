func temLinhaAntes (board [][] byte, i int, j int) bool {
	for a := i - 1; a >= 0; a-- {
		if board [a][j] == 'X' {
			return true // Basta econtrar o primeiro
		} // if board a j == 'X'
	} // for a
	return false // Se chegou até aqui, não encontrou
} // temLinhaAntes

func temLinhaDepois (board [][] byte, i int, j int) bool {
	for a := i + 1; a < len (board); a++ {
		if board [a][j] == 'X' {
			return true // Basta econtrar o primeiro
		} // if board a j == 'X'
	} // for a
	return false // Se chegou até aqui, não encontrou
} // temLinhaDepois

func temColunaAntes (board [][] byte, i int, j int) bool {
	for a := j - 1; a >= 0; a-- {
		if board [i][a] == 'X' {
			return true // Basta econtrar o primeiro
		} // if board i a == 'X'
	} // for a
	return false // Se chegou até aqui, não encontrou
} // temColunaAntes

func temColunaDepois (board [][] byte, i int, j int) bool {
	for a := j + 1; a < len (board [i]); a++ {
		if board [i][a] == 'X' {
			return true // Basta econtrar o primeiro
		} // if board i a == 'X'
	} // for a
	return false // Se chegou até aqui, não encontrou
} // temColunaDepois

func temX (board [][] byte, i int, j int) bool {
	// Optei por dividir em funções especializadas
	// Para facilitar a compreensão
	return temLinhaAntes (board, i, j) &&
		temLinhaDepois (board, i, j) &&
		temColunaAntes (board, i, j) &&
		temColunaDepois (board, i, j)
} // temX

func solve(board [][]byte)  {
	for i := 0; i < len (board); i++ {
		for j := 0; j < len (board [i]); j++ {
			if board [i][j] == 'O' {
				if temX (board, i, j) {
					board [i][j] = 'X'
				} // if temX
			} // if board [i][j] == 'O'
		} // for j
	} // for i
}

