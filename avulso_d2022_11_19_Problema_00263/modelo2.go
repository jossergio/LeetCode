func isUgly(n int) bool {
    if n <= 0 { // Sai logo; não será
        return false
    }
    for _, v := range [3] int {2, 3, 5} {
        for n % v == 0 {
            n /= v
        }
        if n == 1 { // Sai logo
            return true
        }
    }
    return false // Com certeza, n maior que 1 e as divisões não chegaram a definir fatores 2, 3 e/ou 5
}

