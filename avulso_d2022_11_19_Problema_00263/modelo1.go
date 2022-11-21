func isUgly(n int) bool {
    if n <= 0 { // Negativo ou zero
        return false
    }
    // else
    if n == 1 { // Padrão
        return true
    }
    // else
    return (n % 2 == 0 && isUgly (n / 2)) || (n % 3 == 0 && isUgly (n / 3)) || (n % 5 == 0 && isUgly (n / 5))
}

