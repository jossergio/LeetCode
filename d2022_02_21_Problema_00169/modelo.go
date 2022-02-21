func majorityElement(nums []int) int {
    
    valores := make (map [int] int)
    
    for _, v := range nums {
        if _, existe := valores [v]; existe {
            valores [v]++
        } else {
            valores [v] = 1
        }
    }
    
    var maior int // = 0
    var resposta int // 0
    
    for i, v := range valores {
        if v > maior {
            maior = v
            resposta = i
        }
    }
    
    return resposta
}

