func generate(numRows int) [][]int {
    
    var resposta [][] int
    var linha [] int
    
    resposta = append (resposta, [] int {1}) // A primeira linha sempre é essa
    
    if numRows == 1 {
        return resposta
    }

    resposta = append (resposta, [] int {1, 1}) // E a segunda essa

    if numRows == 2 {
        return resposta
    }
    
    for i := 2; i < numRows; i++ { // Só precisamos definir a partir da linha 3 (0-begin)
        
        linha = [] int {1}
        
        for j := 1; j < len (resposta [i - 1]); j++ {
            linha = append (linha, resposta [i - 1][j - 1] + resposta [i - 1][j])
        }
        
        linha = append (linha, 1)
        resposta = append (resposta, linha)
    }
    
    return resposta
}

