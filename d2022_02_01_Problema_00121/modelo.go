func maxProfit(prices []int) int {
    
    var acumulado int = 0
    var maior, menor int = prices [0], prices [0]
    
    for _, v := range prices {
        
        if v > maior {
            maior = v
            tmp := maior - menor
            if tmp > acumulado {
                acumulado = tmp
            }
        }
        
        if v < menor {
            menor = v
            maior = v
            // Redefine
        }
    
    }
    
    return acumulado
    
}

