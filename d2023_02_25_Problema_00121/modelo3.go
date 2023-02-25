func maxProfit(prices []int) int {
    fMaior := func (a int, b int) int {
        if (a > b) {
            return a
        }
        // else
        return b
    }
    var maximo int // = 0
    menor := prices [0] // Sempre haverá, pelo menos, 1
    for _, v := range prices {
        if v < menor {
            menor = v
        } else {
            maximo = fMaior (maximo, v - menor)
        }
    }
    return maximo
}

