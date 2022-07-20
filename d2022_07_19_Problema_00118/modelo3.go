func generate(numRows int) [][]int {
    
    resposta := make ([][] int, numRows)
    
    for i := 0; i < numRows; i++ { // Só precisamos definir a partir da linha 3 (0-begin)
        
        linha := make ([] int, i + 1)
        
        for j := 0; j < len (linha); j++ {
            if j == 0 || j == len (linha) - 1 {
                linha [j] = 1
            } else {
                linha [j] = resposta [i - 1][j - 1] + resposta [i - 1][j] // Essa linha não deve produzir erro mesmo para a 1a linha, pois a condição não deixa
            }
        }
        
        resposta [i] = linha
    }
    
    return resposta
}

