func singleNumber(nums []int) int {
    
    valores := make (map [int] int)
    
    for _, v := range nums {
        if _, existe := valores [v]; existe {
            delete (valores, v)
        } else {
            valores [v] = 1 // Só para criar
        }
    }
    
    for resposta := range valores { // Só haverá um
        return resposta
    }
    
    return 0 // Nunca chega aqui
    
}

