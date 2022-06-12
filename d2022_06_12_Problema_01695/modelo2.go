func maximumUniqueSubarray(nums []int) int {
    
    pNumeros := make (map [int] int)
    
    maior := func (a int, b int) int {
        if a > b {
            return a
        }
        // else
        return b
    }
    
    var resp, tmp, seq int // = 0
    
    for i, v := range nums {
        
        if pos, existe := pNumeros [v]; existe {
            
            resp = maior (resp, tmp)
            
            if seq <= pos {

                for j := seq; j <= pos; j++ { // Tira os números anteriores; inclusive, o atual
                    tmp -= nums [j]
                }

                seq = pos + 1
            }
        }

        tmp += v
        pNumeros [v] = i
    }
    
    return maior (resp, tmp) // Para o caso de ter ficado resquícios
}

