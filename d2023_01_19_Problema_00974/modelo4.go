func subarraysDivByK(nums []int, k int) int {
    restos := make (map [int] int)
    var modulo int // = 0
    var contagem int // = 0
    restos [0] = 1
    for _, num := range nums {
        modulo = (modulo + num % k + k) % k // Evita negativos
        if v, existe := restos [modulo]; existe {
            contagem += v
        } else {
            restos [modulo] = 0
        }
        restos [modulo] += 1
    }
    return contagem
}

