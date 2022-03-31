func isHappy(n int) bool {
    
    if n == 0 {
        return false // LeetCode
    }
    
    passagens := make (map [int] bool) // Para checar se já passou por algum número
    
    passagens [n] = true // n já conta como primeiro número
    
    for n != 1 {
        
        var interno int = n
        
        n = 0 // Inicia o preparo para o próximo ciclo
        
        for (interno != 0) {
            
            v := interno % 10 // Pega o último algarismo
            
            n += v * v
            
            interno /= 10
        }
        
        if _, existe := passagens [n]; existe {
            return false // Iria entrar em laço e não chegaria a 1
        } else {
            passagens [n] = true // Indiferente se é o 1
        }
        
    }
    
    return true // Se conseguiu chegar a 1, encontrou
}

