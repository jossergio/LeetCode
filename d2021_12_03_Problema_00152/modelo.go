func maxProduct(nums []int) int {
    var resposta int = nums [0]
    for len (nums) > 0 {
        var acumulado int = nums [0] // Elemento neutro da multiplicação
        for i, valor := range nums {
            if (i > 0) {
                acumulado *= valor                
            } // if i > 0
            if acumulado > resposta {
                resposta = acumulado
            } // if acumulado > resposta
            if acumulado == 0 { // Dispensa a partir daqui
                break
            } // if acumulado == 0
        } // for i, valor range nums
        nums = nums [1:]
    } // for len nums
    return resposta
}

