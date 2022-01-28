func findMaximumXOR(nums []int) int {
    
    var tamanho int = len (nums)
    var maximo int // = 0
    
    for i := 0; i < tamanho; i++ {
        
        for j := i + 1; j < tamanho; j++ {
            
            tmp := nums [i] ^ nums [j]
            
            if tmp > maximo {
                maximo = tmp
            }
            
        }
        
    }
    
    return maximo
}

