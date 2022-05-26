func hammingWeight(num uint32) int {
    var resp int = 0 // Pode ser qualquer tipo inteiro. Não passa de 32.
    
    for num > 0 {
        if num & 1 == 1 {
            resp++
        }
        num >>= 1
    }
    
    return resp
}

