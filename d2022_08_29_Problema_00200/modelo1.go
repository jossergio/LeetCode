func encontrar1 (tabuleiro [][] byte) (linha, coluna int) {
    // Procura algum 1, para ser o primeiro na busca; retorna -1, -1, se não localizar
    
    for linha = 0; linha < len (tabuleiro); linha++ {
        for coluna = 0; coluna < len (tabuleiro [0]); coluna++ {
            if tabuleiro [linha][coluna] == '1' {
                return // Já estão com os valores
            }
        }
    }
    
    return -1, -1 // Não encontrou
}

func zerar (tabuleiro [][] byte, linha, coluna int) {
    
    tabuleiro [linha][coluna] = '0' // Lembrar que só chega nessa função se a posição for 1
    
    testar := func (l, c int) {
        if l >= 0 && l < len (tabuleiro) && c >= 0 && c < len (tabuleiro [0]) && tabuleiro [l][c] == '1' {
            zerar (tabuleiro, l, c)
        }
    }
    
    // Não se pode usar laço para definir as posições, uma vez que a diagonal não pode ser validada; somente em cruz
    testar (linha - 1, coluna)
    testar (linha + 1, coluna)
    testar (linha, coluna - 1)
    testar (linha, coluna + 1)
}
func numIslands(grid [][]byte) int {
    
    var resposta int // = 0
    
    for true {
        
        l, c := encontrar1 (grid)
        fmt.Println (l, c)

        if l == -1 { // Tanto faz; os dois vem -1 se não houver algum 1
            break 
        }
        
        zerar (grid, l, c) // Irá exterminar os 1s da ilha localizada
        resposta++
        
    }
    
    return resposta
}

