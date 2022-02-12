func subarraySum(nums []int, k int) int {
    var resposta int
    var tamanho int = len (nums)
    
    for inicio := 0; inicio < tamanho; inicio++ {
        var soma int = 0
        for final := inicio; final < tamanho; final++ {
            soma += nums [final]
            if soma == k {
                resposta++
            }
        }
    }
    
    return resposta
}

