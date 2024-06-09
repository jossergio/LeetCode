func subarraysDivByK(nums []int, k int) int {
    restos := make ([] int, k) // Tudo zero
    var modulo int // = 0
    var contagem int // = 0
    restos [0] = 1
    for _, num := range nums {
        modulo = (modulo + num % k + k) % k // Evita negativos
        contagem += restos [modulo]
        restos [modulo] += 1
    }
    return contagem
}

