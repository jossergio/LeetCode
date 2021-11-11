func calcular (nums [] int) int {
    var acumulado int = 1 // Valor mínimo; já registra
    var valorInicial int = 1 // Valor mínimo de retorno
    for _, v := range nums {
        acumulado += v
        for acumulado < 1 {
            valorInicial++
            acumulado++
        }
    }
    return valorInicial
} // calcular

func minStartValue(nums []int) int {
    if len (nums) > 0 {
        return calcular (nums)
    }
    return 1 // Mínimo
}

